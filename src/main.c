#include "../include/cub3d.h"

void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		exit(1);
	display->window = mlx_new_window(display->mlx, 1924, 1512, "Cub3D");
	display->img.img = mlx_new_image(display->mlx, 1924, 1512);
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

void	draw_square(t_image_data *img, int color)
{
	int	x;
	int	y;
	int size;

	x = 100;
	y = 100;
	size = 100;

	while (y < 100 + size)
	{
		x = 100;
		while (x < 100 + size)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
/*
int	main(void)
{
	t_image_data img;
	t_display display;

	init_mlx(&display, &img);
	draw_square(&img, RED);
	ft_mlx_hooks(&display);
	mlx_loop(display.mlx);
	return (0);
}
*/

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Square");

    int x = 100;
    int y = 100;
    int size = 50;
    int color = 0xFF0000; // RGB color (red)

    while (y < 100 + size)
    {
        x = 100;
        while (x < 100 + size)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
            x++;
        }
        y++;
    }

    mlx_loop(mlx_ptr);

    return 0;
}
