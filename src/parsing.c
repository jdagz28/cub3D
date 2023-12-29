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
	int i;

	i = 1;
	if (texture->north == NULL)
		i = 0;
	if (texture->south == NULL)
		i = 0;
	if (texture->west == NULL)
		i = 0;
	if (texture->east == NULL)
		i = 0;
	if (texture->floor == -1)
		i = 0;
	if (texture->ceiling == -1)
		i = 0;
	return (i);
}

char	*check_empty(int fd, char *line) // mettre dans utils.c
{
	while (line && line[0] == '\n')
		line = get_next_line(fd);
	return (line);
}

/*
char	*add_line_to_array(char *line) // mettre dans array.c
{
	char	*new = malloc(ft_strlen(line) + 1);

	if (new == NULL)
		exit(EXIT_FAILURE); // !!exit et free!! (delete)
	ft_strlcpy(new, line, ft_strlen(line));
	return (new);
}

void test_ft(int fd, char *line)
{
	line = check_empty(fd, line);
	while (line)
	{
		printf("Printf line : %s\n", line);
		line = get_next_line(fd);
		//put line in array
	}
}

char	**map_array(int fd, char *line)
{
	int	i;
	int	j;
	char	**array;

	i = 0;
	j = 0;
	array = NULL;
	line = check_empty(fd, line);
	while (line)
	{

		array[i] = add_line_to_array(line);
		line = get_next_line(fd);
		i++;
		//put line in array
	}
	return (array);
}
*/

void print_map(char **map)
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			printf("%c", map[j][i]);
		}
		printf("\n");
	}
}

char	*get_map(int fd, char *line) // rajouter une * pour array
{
	char	*long_line;

	long_line = ft_strdup(line);
	
	line = get_next_line(fd);
	while (line)
	{
		printf("longline = %s\nline = %s\n", long_line, line);
		ft_strlcat(long_line, line, ft_strlen(long_line));
		line = get_next_line(fd);
	}
	printf("Long_line = %s\n", long_line);
	return (long_line); // change return with the array
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
	// fonction check map open
	//test_ft(game->fd, line);
	//print_map(map_array(game->fd, line));
	get_map(game->fd, line);
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
