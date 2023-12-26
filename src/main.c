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

static int	check_color(int color)
{
	if (color == -1)
		return (0);
	else
	{
		printf("Error: Textures not valid.\n");
		printf("color of floor or ceiling\n"); // test
		exit(EXIT_FAILURE);
	}
	return (1);
}

static int	rgb_to_hex(int red, int green, int blue)
{
	int	res;

	res = -2;
	if (red < 0 || red > 255)
		return (-1);
	else if (green < 0 || green > 255)
		return (-1);
	else if (blue < 0 || blue > 255)
		return (-1);
	else
		res = (red << 16) | (green << 8) | blue;
	printf("RGB = %d, %d, %d\n", red, green, blue);
	printf("Hexa = %d\n", res);
	return (res);
}

static int	get_rgb(t_texture *texture, char c, char *path) // SEGFAULT ICI !!!ERROR
{
	char	**split;

	split = ft_split(path, ',');
	if (!split[0] || !split[1] || !split[2])
		return (-1); // print texture incorrecte
	if (split[3])
	{
		printf("split[3] pas cense exister\n");
		return (1);
	}
	if (c == 'F')
	{
		printf("c == F\n");
		if (texture->floor == -1)
			texture->floor = rgb_to_hex(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
		else
		{
			printf("Error color floor\n");
			return (-1);
		}
	}
	else if (c == 'C')
	{
		printf("c == C\n");
		printf("%d\n", texture->ceiling);
		if (texture->ceiling == -1) // cette ligne segfault
			texture->ceiling = rgb_to_hex(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
		else
		{
			printf("Error color ceiling\n");
			return (-1);
		}
	}
	free(split);
	return (0);
}

static void	assign_texture(t_texture *texture, char *direction, char *path)
{
	if (ft_strncmp(direction, "NO", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->north)))
				texture->north = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "SO", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->south)))
				texture->south = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "WE", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->west)))
				texture->west = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "EA", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->east)))
				texture->east = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "F", ft_strlen(direction)) == 0)
	{
		if (!(check_color(texture->floor)))
			get_rgb(texture, 'F', path);
	}
	if (ft_strncmp(direction, "C", ft_strlen(direction)) == 0)
		if (!(check_color(texture->ceiling)))
			get_rgb(texture, 'C', path);
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
	if (i == 1) //test
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
	free(split);
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
	texture->rgb = -1;
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
	printf("** Printfs dans la main pour check si toutes les textures sont correctes\n");
	printf("Floor = %d\n", game.texture.floor);
	printf("Ceiling = %d\n", game.texture.ceiling);
	printf("North  = %s\n", game.texture.north);
	printf("South  = %s\n", game.texture.south);
	printf("West  = %s\n", game.texture.west);
	printf("East  = %s\n", game.texture.east);
	printf("Floor = %d\n", game.texture.floor);
	printf("Ceiling = %d\n", game.texture.ceiling);
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
