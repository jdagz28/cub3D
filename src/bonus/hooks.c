#include "../include/cub3d.h"

int	close_window_cross(t_display *display)
{
	mlx_destroy_image(display->mlx, display->img.img);
	mlx_destroy_window(display->mlx, display->window);
	exit(0);
}

int	keybindings(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		close_window_cross(&game->display);
	else if (keycode == K_W || keycode == K_S)
		player_movement_y(keycode, game);
	else if (keycode == K_A || keycode == K_D)
		player_movement_x(keycode, game);
	else if (keycode == K_RIGHT)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle = 2 * M_PI;
		update_player_front(&game->player);
	}
	else if (keycode == K_LEFT)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * M_PI)
			game->player.angle = 0;
		update_player_front(&game->player);
	}
	return (0);
}

