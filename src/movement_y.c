/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:29 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/20 22:03:34 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_y(t_game *game, int x, int y, int keycode)
{
	if (keycode == K_W)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] += game->player.front.dir[X];
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.front.dir[Y];
	}
	if (keycode == K_S)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[X];
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[Y];
	}
}

static void	move_backward(t_game *game, int keycode)
{
	int	x_offset;
	int	y_offset;
	int	sub_x;
	int	sub_y;

	x_offset = 20;
	if (game->player.front.dir[X] < 0)
		x_offset = -20;
	y_offset = 20;
	if (game->player.front.dir[Y] < 0)
		y_offset = -20;
	sub_x = (game->player.position.axis[X] - x_offset) / TILE_SIZE;
	sub_y = (game->player.position.axis[Y] - y_offset) / TILE_SIZE;
	move_y(game, sub_x, sub_y, keycode);
}

static int	check_adjacent(t_game *game, int x_offset, int y_offset)
{
	int	check_x;
	int	check_y;

	check_x = (game->player.position.axis[X] + x_offset) / TILE_SIZE;
	check_y = (game->player.position.axis[Y] + y_offset) / TILE_SIZE;
	if (game->map[check_y][check_x] == '0')
		return (0);
	return (1);
}

static void	move_forward(t_game *game, int keycode)
{
	int	x_offset;
	int	y_offset;
	int	add_x;
	int	add_y;

	x_offset = 20;
	if (game->player.front.dir[X] < 0)
		x_offset = -20;
	y_offset = 20;
	if (game->player.front.dir[Y] < 0)
		y_offset = -20;
	if (check_adjacent(game, x_offset, y_offset) == 0)
	{
		add_x = (game->player.position.axis[X] + x_offset) / TILE_SIZE;
		add_y = (game->player.position.axis[Y] + y_offset) / TILE_SIZE;
		move_y(game, add_x, add_y, keycode);
	}
}

void	player_movement_y(int keycode, t_game *game)
{
	if (check_playerpos(game) == 0)
		return ;
	if (keycode == K_W)
		move_forward(game, keycode);
	if (keycode == K_S)
		move_backward(game, keycode);
}
