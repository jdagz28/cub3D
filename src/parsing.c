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

char	*check_empty(int fd, char *line) // mettre dans utils.c
{
	while (line && line[0] == '\n')
		line = get_next_line(fd);
	return (line);
}

/*
void print_map(char **map)
{
	int i, j;
	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/

char	**get_map(int fd, char *start) // rajouter une * pour array
{
	char	*line;
	char	**array;

	start = check_empty(fd, start);
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

// Lire line apres line et les ajoutes a long_line

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
