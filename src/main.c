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
	len = (int)ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		printf("Error\nMap is not .cub\n");
		exit(EXIT_FAILURE);
	}
}

static void	get_texture(char *line)
{
	int i;

	i = 0;
	if (line[0] == 'N' && line[1] == 'O')
	{
		//struct_data_North = le path (line[3] jusque line[dernier element])
		printf("NO\n");
	} // quand je stock un elem, check avant si il y a deja qq chose
	// si oui -> message d'erreur
	else if (line[0] == 'W' && line[1] == 'E')
		printf("WE\n");
	else if (line[0] == 'S' && line[1] == 'O')
		printf("SO\n");
	else if (line[0] == 'E' && line[1] == 'A')
		printf("EA\n");
	else if (line[0] == 'F')
		printf("F\n");
	else if (line[0] == 'C')
		printf("C\n");
}

static void	get_map_data(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			line = get_next_line(fd);
		printf("Line = %s", line);
		get_texture(line);
		line = get_next_line(fd);
	}
	// fonction qui check si toutes les donnees sont bien presents dans la struct
	// pendant le parsing fonction qui check si on remplis pas plusieurs fois la meme donnees
}

int	parsing(int argc, char **argv)
{
	int fd;

	fd = 0;
	arg_error(argc, argv);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(1);
	get_map_data(fd);
	close(fd); // va avec fd = open
	return (0);
}

int	main(int argc, char **argv)
{
	parsing(argc, argv);
	return (0);
}

/**************************************************/
void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (!display->mlx)
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
