/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2Dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:44:29 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/03 14:35:29 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

static void	draw_playerpos(t_display *mlx, t_player *player, \
							int axis[2], int radius)
{
	int	pixel;
	int	new_axis[2];

	new_axis[X] = player->position.axis[X] + axis[X];
	new_axis[Y] = player->position.axis[Y] + axis[Y];
	if (new_axis[X] >= 0 && new_axis[X] < WIDTH \
		&& new_axis[Y] >= 0 && new_axis[Y] < HEIGHT && \
		axis[X] * axis[X] + axis[Y] * axis[Y] \
		<= radius * radius)
	{
		pixel = new_axis[Y] * (WIDTH * 4) + new_axis[X] * 4;
		set_color(&mlx->img.address[pixel], mlx->img.endian, RED, 1);
	}
}

static void	draw_player(t_gametest *game)
{
	int			axis[2];
	int			radius;

	radius = 10;
	axis[X] = -radius;
	while (axis[X] <= radius)
	{
		axis[Y] = -radius;
		while (axis[Y] <= radius)
		{
			draw_playerpos(&game->display, &game->player, axis, radius);
			axis[Y]++;
		}
		axis[X]++;
	}
}

void	draw_minimap(t_gametest *game)
{
	draw_maptiles(game, &game->display);
	draw_grids(&game->display);
	draw_player(game);
}


