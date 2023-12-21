#include "../include/cub3d.h"

// PARSING DE LA  MAP

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

static int	check_texture(void *texture)
{
	if (texture == NULL)
		return (0);
	else
	{
		printf("Error: Textures not valid.\n");
		printf("---------> %s\n", texture); // test
		exit(EXIT_FAILURE);
	}
	return (1);
}

static void	assign_texture(t_texture *texture, char* direction, char *path)
{
	if (ft_strncmp(direction, "NO", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->north)))
				texture->north = path;
	if (ft_strncmp(direction, "SO", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->south)))
				texture->south = path;
	if (ft_strncmp(direction, "WE", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->west)))
				texture->west = path;
	if (ft_strncmp(direction, "EA", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->east)))
				texture->east = path;
	if (ft_strncmp(direction, "F", ft_strlen(direction)) == 0)
		printf("ceci est un F\n");
	if (ft_strncmp(direction, "C", ft_strlen(direction)) == 0)
		printf("ceci est un C\n");
}


static int	len_split(char **split)
{
	int i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
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
	if (i == 1) //test + RAJOUTER LE CHECK POUR CEILING ET FLOOR
		printf("Toutes les textures sont assignees\n"); // test
	return (i);
}

static void	get_texture(t_texture *texture, char *line)
{
	char **split;

	split = ft_split(line, ' ');
	if (len_split(split) != 2)
	{
		if (len_split(split) != 0)
		{
			printf("This line is not valid -> %s\n", line); // test
			printf("Texture path is not valid.\n");
			exit(EXIT_FAILURE);
		}
	}
	if (!split)
		return ;
	assign_texture(texture, split[0], split[1]);
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

static void	init_textures(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = -1;
	texture->ceiling = -1;
}

t_game *init_game(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->map = NULL;
	game->fd = 0;
	init_textures(&game->texture);
	return (game);
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

int	main(int argc, char **argv)
{
	t_game	game;

	parsing(argc, argv, &game);
	return (0);
}

/**************************************************/
void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
		exit(1);
	display->window = mlx_new_window(display->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	display->img.img = mlx_new_image(display->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_image_data *img, int color, int coord_x, int coord_y)
{
	int	x;
	int y;
	int	size;

	size = 50;
	y = coord_y;
	while (y < coord_y + size)
	{
		x = coord_x;
		while (x < coord_x + size)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

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

char	**get_map(void)
{
	char **map;

	map = malloc(sizeof(char*) * 5);
	for (int i = 0; i < 6; i++)
		map[i] = malloc(sizeof(char) * 7);
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 6; i++)
			map[j][i] = '0';
	}
	for (int i = 0; i < 7; i++)
	{
		map[0][i] = '1';
		map[4][i] = '1';
	}
	for (int i = 0; i < 5; i++)
	{
		map[i][0] = '1';
		map[i][6] = '1';
	}
	map[1][3] = '1';
	map[3][4] = 'N';
	return (map);
}
/*
int main(void)
{
	char **map;

	map = get_map();
	print_map(map);
	return (0);
}
*/

/*
int	main(void)
{
	t_image_data img;
	t_display display;

	int i = ft_isalnum(14);
	i += 1;
	init_mlx(&display, &img);
	draw_square(&img, RED, 200, 200);
	mlx_put_image_to_window(display.mlx, display.window, display.img.img, 0, 0);
	ft_mlx_hooks(&display);
	mlx_loop(display.mlx);
	return (0);
}
*/
