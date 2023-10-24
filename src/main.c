#include "../include/cub3d.h"

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

int main(void)
{
	char **map;

	map = get_map();
	print_map(map);
	return (0);
}

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
