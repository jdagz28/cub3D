/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maptiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:42:06 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/19 00:57:01 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

void	fill_maptile(t_display *mlx, int x, int y)
{
	int	axis[2];
	int	pixel;

	x = x * TILE_SIZE;
	y = y * TILE_SIZE;
	axis[X_AXIS] = 0;
	while (axis[X_AXIS] < TILE_SIZE)
	{
		axis[Y_AXIS] = 0;
		while (axis[Y_AXIS] < TILE_SIZE)
		{
			pixel = (axis[Y_AXIS] + y) * (WIDTH * 4) \
						+ (axis[X_AXIS] + x) * 4;
			set_color(&mlx->img.address[pixel], \
				mlx->img.endian, WHITE, 1);
			axis[Y_AXIS]++;
		}
		axis[X_AXIS]++;
	}
}

void	draw_maptiles(t_gametest *game, t_display *mlx)
{
	int	axis[2];

	axis[X_AXIS] = 0;
	while (axis[X_AXIS] < game->map_height)
	{
		axis[Y_AXIS] = 0;
		while (axis[Y_AXIS] < game->map_width)
		{
			if (game->map[axis[X_AXIS]][axis[Y_AXIS]] == 1)
				fill_maptile(mlx, axis[Y_AXIS], axis[X_AXIS]);
			axis[Y_AXIS]++;
		}
		axis[X_AXIS]++;
	}	
}
