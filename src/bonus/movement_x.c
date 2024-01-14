/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:27:27 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/14 18:09:29 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cal_side_direction(t_vector *front, t_vector *side)
{
	side->dir[X] = -front->dir[Y];
	side->dir[Y] = front->dir[X];
}

static void	move_x(t_game *game, int x, int y, int keycode)
{
	if (keycode == K_A)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] -= game->player.side.dir[X];
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.side.dir[Y];
	}
	if (keycode == K_D)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] += game->player.side.dir[X];
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.side.dir[Y];
	}
}

static void	move_right(t_game *game, int keycode)
{
	int	x_offset;
	int	y_offset;
	int	add_x;
	int	add_y;

	x_offset = 20;
	if (game->player.side.dir[X] < 0)
		x_offset = -20;
	y_offset = 20;
	if (game->player.side.dir[Y] < 0)
		y_offset = -20;
	add_x = (game->player.position.axis[X] + x_offset) / TILE_SIZE;
	add_y = (game->player.position.axis[Y] + y_offset) / TILE_SIZE;
	move_x(game, add_x, add_y, keycode);
}

static void	move_left(t_game *game, int keycode)
{
	int	x_offset;
	int	y_offset;
	int	sub_x;
	int	sub_y;

	x_offset = 20;
	if (game->player.side.dir[X] < 0)
		x_offset = -20;
	y_offset = 20;
	if (game->player.side.dir[Y] < 0)
		y_offset = -20;
	sub_x = (game->player.position.axis[X] - x_offset) / TILE_SIZE;
	sub_y = (game->player.position.axis[Y] - y_offset) / TILE_SIZE;
	move_x(game, sub_x, sub_y, keycode);
}

void	player_movement_x(int keycode, t_game *game)
{
	if (check_playerpos(game) == 0)
		return ;
	cal_side_direction(&game->player.front, &game->player.side);
	if (keycode == K_A)
		move_left(game, keycode);
	if (keycode == K_D)
		move_right(game, keycode);
}
