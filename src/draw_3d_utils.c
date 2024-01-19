/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:59:15 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/19 10:09:37 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	check_rayhit(t_game *game, float x)
{
	if (game->ray.hit == 1)
	{
		x = (int)(game->ray.x / 3) % TILE_SIZE;
		if (get_direction(game) == SOUTH)
			return (TILE_SIZE - x - 1);
	}
	else
	{
		x = (int)(game->ray.y / 2) % TILE_SIZE;
		if (get_direction(game) == WEST)
			return (TILE_SIZE - x - 1);
	}
	return (x);
}

float	fix_fisheye(t_game *game)
{
	float	angle;

	angle = game->player.angle - game->ray.angle;
	if (angle < 0)
		return (angle += 2 * M_PI);
	if (angle > 2 * M_PI)
		return (angle -= 2 * M_PI);
	return (angle);
}

int	get_direction(t_game *game)
{
	if (game->ray.hit == 1)
	{
		if (game->ray.angle > M_PI)
			return (SOUTH);
		else
			return (NORTH);
	}
	else if (game->ray.angle > M_PI_2 && game->ray.angle < M_PI_3)
		return (WEST);
	else
		return (EAST);
}
