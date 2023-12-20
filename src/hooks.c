#include "../include/cub3d.h"

int	close_window(int keycode, t_display *display)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_image(display->mlx, display->img.img);
		mlx_destroy_window(display->mlx, display->window);
		exit(0);
	}
	return (0);
}

int	close_window_cross(t_display *display)
{
	mlx_destroy_image(display->mlx, display->img.img);
	mlx_destroy_window(display->mlx, display->window);
	exit(0);
}

void	ft_mlx_hooks(t_display *display)
{
	mlx_key_hook(display->window, close_window, display);
	mlx_hook(display->window, ON_DESTROY, 0, close_window_cross, display);
}
