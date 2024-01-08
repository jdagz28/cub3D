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

int movement_y_offset(t_game *game, char *type, int value)
{
	int res;

	res = 0;
	if (value < 0)
		res = 0;
	else if (ft_strncmp(type, "add_x", ft_strlen(type)) == 0 || \
				ft_strncmp(type, "sub_x", ft_strlen(type)) == 0)
		res = game->map_width;
	else if (ft_strncmp(type, "add_y", ft_strlen(type)) == 0 || \
				ft_strncmp(type, "sub_y", ft_strlen(type)) == 0)
		res = game->map_height;
	return res;
}


void	player_movement_y(int keycode, t_game *game)
{
	int	add_x;
	int	add_y;
	int	sub_x;
	int	sub_y;

	if (check_playerpos(game) == 0)
		return ;
	add_x = (game->player.position.axis[X] - game->player.front.dir[X]) / TILE_SIZE - 0.2;
	if (add_x < 0 || add_x > game->map_width)
		add_x = movement_y_offset(game, "add_x", add_x);
	add_y = (game->player.position.axis[Y] - game->player.front.dir[Y]) / TILE_SIZE - 0.2;
	if (add_y < 0 || add_y > game->map_height)
		add_y = movement_y_offset(game, "add_y", add_y);
	sub_x = (game->player.position.axis[X] + game->player.front.dir[X]) / TILE_SIZE + 0.2;
	if (sub_x < 0 || sub_x > game->map_width)
		sub_x = movement_y_offset(game, "sub_x", sub_x);
	sub_y = (game->player.position.axis[Y] + game->player.front.dir[Y]) / TILE_SIZE + 0.2;
	if (sub_y < 0 || sub_y > game->map_height)
		sub_y = movement_y_offset(game, "sub_y", sub_y);
	if (keycode == K_W)
	{
		if (game->map[game->player.array_y][add_x] == '0')
			game->player.position.axis[X] += game->player.front.dir[X];
		if (game->map[add_y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.front.dir[Y];
	}
	if (keycode == K_S)
	{
		if (game->map[game->player.array_y][sub_x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[X];
		if (game->map[sub_y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[Y];
	}
}

void	player_movement_x(int keycode, t_game *game)
{
	int	add_x;
	int	add_y;
	int	sub_x;
	int	sub_y;

	if (check_playerpos(game) == 0)
		return ;
	add_x = (game->player.position.axis[X] + game->player.front.dir[Y]) / TILE_SIZE - 0.1;
	if (add_x < 0 || add_x > game->map_width)
	{
		if (add_x < 0)
			add_x = 0;
		else
			add_x = game->map_width;
	}
	add_y = (game->player.position.axis[Y] - game->player.front.dir[X]) / TILE_SIZE - 0.1;
	if (add_y < 0 || add_y > game->map_height)
	{
		if (add_y < 0)
			add_y = 0;
		else
			add_y = game->map_height;
	}
	sub_x = (game->player.position.axis[X] - game->player.front.dir[Y]) / TILE_SIZE + 0.1;
	if (sub_x < 0 || sub_x > game->map_width)
	{
		if (sub_x < 0)
			sub_x = 0;
		else
			sub_x = game->map_width;
	}
	sub_y = (game->player.position.axis[Y] - game->player.front.dir[X]) / TILE_SIZE + 0.1;
	if (sub_y < 0 || sub_y > game->map_height)
	{
		if (sub_y < 0)
			sub_y = 0;
		else
			sub_y = game->map_height;
	}
	if (keycode == K_A)
	{
		if (game->map[game->player.array_y][add_x] == '0')
			game->player.position.axis[X] += game->player.front.dir[Y];
		if (game->map[add_y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[X];
	}
	if (keycode == K_D)
	{
		if (game->map[game->player.array_y][sub_x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[Y];
		if (game->map[sub_y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.front.dir[X];
	}
}

void	open_door(int keycode, t_game *game)
{

	int	add_x;
	int	add_y;

	add_x = (game->player.position.axis[X] - game->player.front.dir[X]) / TILE_SIZE - 0.5;
	if (add_x < 0 || add_x > game->map_width)
	{
		if (add_x < 0)
			add_x = 0;
		else
			add_x = game->map_width;
	}
	add_y = (game->player.position.axis[Y] - game->player.front.dir[Y]) / TILE_SIZE - 0.5;
	if (add_y < 0 || add_y > game->map_height)
	{
		if (add_y < 0)
			add_y = 0;
		else
			add_y = game->map_height;
	}
	if (keycode == K_E)
	{
		printf("x:%d y:%d\n", add_x, game->player.array_y);
		if (game->player.array_y >= 0 && game->player.array_y < game->map_height && add_x >= 0 && add_x < game->map_width)
			if (game->map[game->player.array_y][add_x] == '3')
				game->map[game->player.array_y][add_x] = '0';

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
	else if (keycode == K_W || keycode == K_S)
		player_movement_y(keycode, game);
	else if (keycode == K_A || keycode == K_D)
		player_movement_x(keycode, game);
	else if (keycode == K_E)
		open_door(keycode, game);
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

