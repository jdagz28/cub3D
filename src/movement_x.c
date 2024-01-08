/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:27:27 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/08 12:29:02 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_x(t_game *game, int x, int y, int keycode)
{
	if (keycode == K_A)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] += game->player.front.dir[Y] * MOVE_SPEED;
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[X] * MOVE_SPEED;
	}
	if (keycode == K_D)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[Y] * MOVE_SPEED;
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.front.dir[X] * MOVE_SPEED;
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
		add_x = offset_check(game, "add_x", add_x);
	add_y = (game->player.position.axis[Y] - game->player.front.dir[X]) / TILE_SIZE - 0.1;
	if (add_y < 0 || add_y > game->map_height)
		add_y = offset_check(game, "add_y", add_y);
	sub_x = (game->player.position.axis[X] - game->player.front.dir[Y]) / TILE_SIZE + 0.1;
	if (sub_x < 0 || sub_x > game->map_width)
		sub_x = offset_check(game, "sub_x", sub_x);
	sub_y = (game->player.position.axis[Y] - game->player.front.dir[X]) / TILE_SIZE + 0.1;
	if (sub_y < 0 || sub_y > game->map_height)
		sub_y = offset_check(game, "sub_y", sub_y);
	if (keycode == K_A)
		move_x(game, add_x, add_y, keycode);
	if (keycode == K_D)
		move_x(game, sub_x, sub_y, keycode);
}
