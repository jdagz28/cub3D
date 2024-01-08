#include "../include/cub3d.h"

//! Not yet functional
// void	open_door(int keycode, t_game *game)
// {

// 	int	add_x;
// 	int	add_y;

// 	add_x = (game->player.position.axis[X] - game->player.front.dir[X]) / TILE_SIZE - 0.5;
// 	if (add_x < 0 || add_x > game->map_width)
// 	{
// 		if (add_x < 0)
// 			add_x = 0;
// 		else
// 			add_x = game->map_width;
// 	}
// 	add_y = (game->player.position.axis[Y] - game->player.front.dir[Y]) / TILE_SIZE - 0.5;
// 	if (add_y < 0 || add_y > game->map_height)
// 	{
// 		if (add_y < 0)
// 			add_y = 0;
// 		else
// 			add_y = game->map_height;
// 	}
// 	if (keycode == K_E)
// 	{
// 		printf("x:%d y:%d\n", add_x, game->player.array_y);
// 		if (game->player.array_y >= 0 && game->player.array_y < game->map_height && add_x >= 0 && add_x < game->map_width)
// 			if (game->map[game->player.array_y][add_x] == '3')
// 				game->map[game->player.array_y][add_x] = '0';

// 	}
// }

int	keybindings(int keycode, t_game *game)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_image(game->display.mlx, game->display.img.img);
		mlx_destroy_window(game->display.mlx, game->display.window);
		exit(0);
	}
	else if (keycode == K_W || keycode == K_S)
		player_movement_y(keycode, game);
	else if (keycode == K_A || keycode == K_D)
		player_movement_x(keycode, game);
	// else if (keycode == K_E)
	// 	open_door(keycode, game);
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

