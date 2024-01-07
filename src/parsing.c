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

// Return 1 si toutes les textures sont assignees
static	int check_all_textures(t_texture *texture)
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

char	*skip_empty_line(int fd, char *line) // mettre dans utils.c
{
	while (line && line[0] == '\n')
		line = get_next_line(fd);
	return (line);
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

int	check_char(char	c)
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

int	check_char_map(char **map)
{
	int	i;
	int	j;
	int	spawn;

	i = 0;
	spawn = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_char(map[i][j]) == 0)
			{
				printf("Error: Wrong char in map\n");
				exit(1); // free + delete
			}
			else if (check_char(map[i][j]) == 2)
				map[i][j] = '2';
			else if (check_char(map[i][j]) == 3)
					spawn += 1;
			j++;
		}
		i++;
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
	check_char_map(game->map);
	if (check_borders_horizontal(game->map))
		printf("border pas bon\n");
	//check_open_map(game->map);
	//print_map(game->map); // (delete)
}

int	parsing(int argc, char **argv, t_game *game)
{
	arg_error(argc, argv);
	init_game(game);
	if ((game->fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Error: Can't open file.\n");
		exit(1);
	}
	get_data(game);
	close(game->fd); // va avec fd = open
	return (0);
}
