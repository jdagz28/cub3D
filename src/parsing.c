#include "../include/cub3d.h"

static void	arg_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		printf("Error\nMap is not .cub\n");
		exit(EXIT_FAILURE);
	}
}

static int	check_all_textures(t_texture *texture)
{
	if (texture->north == NULL)
		return (0);
	if (texture->south == NULL)
		return (0);
	if (texture->west == NULL)
		return (0);
	if (texture->east == NULL)
		return (0);
	if (texture->floor == -1)
		return (0);
	if (texture->ceiling == -1)
		return (0);
	return (1);
}

char	**get_map(int fd, char *start)
{
	char	*line;
	char	**array;

	start = skip_empty_line(fd, start);
	line = get_next_line(fd);
	while (line)
	{
		start = ft_strjoin(start, line);
		line = get_next_line(fd);
	}
	free(line);
	array = ft_split(start, '\n');
	return (array);
}

//Check_map.c

int	check_char(char c)
{
	if (c == '0' || c == '1')
		return (1);
	else if (c == ' ')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (3);
	else
		return (0);
}

int	check_char_map(char **map, t_player *player)
{
	int	x;
	int	y;
	int	spawn;

	x = 0;
	spawn = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (check_char(map[x][y]) == 0)
			{
				printf("Error: Wrong char in map\n");
				exit(1); // free + delete
			}
			else if (check_char(map[x][y]) == 2)
				map[x][y] = '2';
			else if (check_char(map[x][y]) == 3)
			{
				player->mat_position.axis[0] = y;
				player->mat_position.axis[1] = x;
				player->direction = map[x][y];
				map[x][y] = '0';
				spawn += 1;
			}
			y++;
		}
		x++;
	}
	if (spawn != 1)
	{
		printf("Error: More than one spawn\n");
		exit(1); // free et delete
	}
	return (0);
}

static void	get_data(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(game->fd);
	while (line && !check_all_textures(&game->texture))
	{
		while (line && line[0] == '\n')
			line = get_next_line(game->fd);
		get_texture(&game->texture, line);
		if (line && line[0] != '\0')
			line = get_next_line(game->fd);
		else
			break ;
	}
	if (!check_all_textures(&game->texture))
	{
		printf("Test: Manque des textures\n");
		exit(1);
	}
	game->map = get_map(game->fd, line);
	check_char_map(game->map, &game->player);
	check_wall_map(game->map, game->player.mat_position.axis[0],
		game->player.mat_position.axis[1]);
}

int	parsing(int argc, char **argv, t_game *game)
{
	arg_error(argc, argv);
	init_game(game);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		printf("Error: Can't open file.\n");
		exit(1);
	}
	get_data(game);
	close(game->fd);
	return (0);
}
