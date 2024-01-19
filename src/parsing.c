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
	char	*temp;

	start = skip_empty_line(fd, start);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(start, line);
		free(start);
		if (!temp)
			return (NULL);
		start = temp;
		line = next_line(fd, line);
	}
	free(line);
	array = ft_split(start, '\n');
	free(start);
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

void	fill_array(t_player *player, int x, int y, char z)
{
	player->array_x = x;
	player->array_y = y;
	player->direction = z;
}

void	check_char_map(t_game *game, char **map, t_player *player)
{
	int	coord[3];

	coord[0] = 0;
	coord[2] = 0;
	while (map[coord[0]])
	{
		coord[1] = 0;
		while (map[coord[0]][coord[1]])
		{
			if (check_char(map[coord[0]][coord[1]]) == 0)
				error_manager(game, "Wrong char in map.");
			else if (check_char(map[coord[0]][coord[1]]) == 2)
				map[coord[0]][coord[1]] = '2';
			else if (check_char(map[coord[0]][coord[1]]) == 3)
			{
				fill_array(player, coord[1], coord[0], map[coord[0]][coord[1]]);
				map[coord[0]][coord[1]] = '0';
				coord[2] += 1;
			}
			coord[1]++;
		}
		coord[0]++;
	}
	if (coord[2] != 1)
		error_manager(game, "More than one spawn.");
}

void	map_functions(t_game *game, char *line)
{
	game->map = get_map(game->fd, line);
	if (game->map == NULL)
		error_manager(game, "Map parsing error");
	check_char_map(game, game->map, &game->player);
	check_wall_map(game->map, game->player.array_x,
		game->player.array_y);
	replace_threes(game->map);
}

static void	get_data(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line && !check_all_textures(&game->texture))
	{
		while (line && line[0] == '\n')
			line = next_line(game->fd, line);
		get_texture(game, &game->texture, line);
		if (game->texture.ceiling == 1 || game->texture.floor == 1)
		{
			free(line);
			error_manager(game, "Parsing floor/ceiling color");
		}
		if (line && line[0] != '\0')
			line = next_line(game->fd, line);
		else
			break ;
	}
	if (!check_all_textures(&game->texture))
	{
		free(line);
		error_manager(game, "Missing textures.");
	}
	map_functions(game, line);
}

int	parsing(int argc, char **argv, t_game *game)
{
	arg_error(argc, argv);
	init_game(game);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		printf("Error\nCan't open file.\n");
		exit(1);
	}
	get_data(game);
	close(game->fd);
	return (0);
}
