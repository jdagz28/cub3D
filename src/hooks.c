#include "../include/cub3d.h"

int	check_playerpos(t_game *game)
{
	game->player.array_x = (int)game->player.position.axis[X] / TILE_SIZE;
	game->player.array_y = (int)game->player.position.axis[Y] / TILE_SIZE;
	if (game->player.array_x < 0)
		return (0);
	if (game->player.array_y < 0)
		return (0);
	return (1);
}

void	player_movement_y(int keycode, t_game *game)
{
	int	add_x;
	int	add_y;
	// int	sub_x;
	// int	sub_y;

	if (check_playerpos(game) == 0)
		return ;
	add_x = (game->player.position.axis[X] + game->player.front.dir[X]) / TILE_SIZE;
	if (add_x < 0 || add_x > game->map_width)
	{
		if (add_x < 0)
			add_x = 0;
		else
			add_x = game->map_width;
	}
	add_y = (game->player.position.axis[Y] + game->player.front.dir[Y]) / TILE_SIZE;
	if (add_y < 0 || add_y > game->map_height)
	{
		if (add_y < 0)
			add_y = 0;
		else
			add_y = game->map_height;
	}
	if (keycode == K_S)
	{
		if (game->map[game->player.array_y][add_x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[X];
		if (game->map[add_y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[Y];
	}
}


int	keybindings(int keycode, t_game *game)
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
		player_movement_y(keycode, game);
	else if (keycode == K_A)
	{
		game->player.position.axis[X] += -sin(game->player.angle) * 5;
		game->player.position.axis[Y] += -cos(game->player.angle) * 5;
	}
	else if (keycode == K_D)
	{
		game->player.position.axis[X] += sin(game->player.angle) * 5;
		game->player.position.axis[Y] += cos(game->player.angle) * 5;
	}
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

