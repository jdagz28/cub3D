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
	if (i == 1) //test
		printf("Toutes les textures sont assignees\n"); // test (delete)
	return (i);
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
		printf("Commencer check de map\n");
	// fonction check map open
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
