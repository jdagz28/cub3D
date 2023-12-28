#include "../include/cub3d.h"
#include "map2dtest.h"

int	keybindings(int keycode, t_gametest *game)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_image(game->display.mlx, game->display.img.img);
		mlx_destroy_window(game->display.mlx, game->display.window);
		exit(0);
	}
	else if (keycode == K_W)
	{
		game->player.position.axis[X] += game->player.front.dir[X];
		game->player.position.axis[Y] += game->player.front.dir[Y];
	}
	else if (keycode == K_S)
	{
		game->player.position.axis[X] -= game->player.front.dir[X];
		game->player.position.axis[Y] -= game->player.front.dir[Y];
	}
	else if (keycode == K_D)
	{
		game->player.position.axis[X] += -sin(game->player.angle) * 5;
		game->player.position.axis[Y] += cos(game->player.angle) * 5;
	}
	else if (keycode == K_A)
	{
		game->player.position.axis[X] += sin(game->player.angle) * 5;
		game->player.position.axis[Y] += -cos(game->player.angle) * 5;
	}
	else if (keycode == K_LEFT)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += 2 * M_PI;
		update_player_front(&game->player);
	}
	else if (keycode == K_RIGHT)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * M_PI)
			game->player.angle -= 2 * M_PI;
		update_player_front(&game->player);
	}
	return (0);
}

int	close_window_cross(t_display *display)
{
	mlx_destroy_image(display->mlx, display->img.img);
	mlx_destroy_window(display->mlx, display->window);
	exit(0);
}

// void	ft_mlx_hooks(t_display *display)
// {
// 	mlx_key_hook(display->window, close_window, display);
// 	mlx_hook(display->window, ON_DESTROY, 0, close_window_cross, display);
// }

