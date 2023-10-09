#include "../include/cub3d.h"

void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		exit(1);
	display->window = mlx_new_window(display->mlx, 920, 480, "Cub3D");
	display->img.img = mlx_new_image(display->mlx, 920, 480);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

int main(void)
{
	t_image_data img;
	t_display display;

	init_mlx(&display, &img);
	ft_mlx_hooks(&display);
	mlx_loop(display.mlx);
	return (0);
}
