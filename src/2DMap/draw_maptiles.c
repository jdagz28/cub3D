/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maptiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:42:06 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/28 13:00:04 by jdagoy           ###   ########.fr       */
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
	axis[X] = 0;
	while (axis[X] < TILE_SIZE)
	{
		axis[Y] = 0;
		while (axis[Y] < TILE_SIZE)
		{
			pixel = (axis[Y] + y) * (WIDTH * 4) \
						+ (axis[X] + x) * 4;
			set_color(&mlx->img.address[pixel], \
				mlx->img.endian, WHITE, 1);
			axis[Y]++;
		}
		axis[X]++;
	}
}

void	draw_maptiles(t_gametest *game, t_display *mlx)
{
	int	axis[2];

	axis[X] = 0;
	while (axis[X] < game->map_height)
	{
		axis[Y] = 0;
		while (axis[Y] < game->map_width)
		{
			if (game->map[axis[X]][axis[Y]] == 1)
				fill_maptile(mlx, axis[Y], axis[X]);
			axis[Y]++;
		}
		axis[X]++;
	}	
}
