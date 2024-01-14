/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maptiles_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:42:06 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/09 10:05:05 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_grids(t_display *mlx)
{
	int		axis[2];
	t_point	end;

	axis[Y] = 0;
	while (axis[Y] < WIN_WIDTH)
	{
		end = create_point(axis[Y], WIN_HEIGHT);
		end.color = GRAY;
		draw_line_dda(&mlx->img, create_point(axis[Y], 0), end);
		axis[Y] += TILE_SIZE;
	}
	axis[X] = 0;
	while (axis[X] < WIN_HEIGHT)
	{
		end = create_point(WIN_WIDTH, axis[X]);
		end.color = GRAY;
		draw_line_dda(&mlx->img, create_point(0, axis[X]), end);
		axis[X] += TILE_SIZE;
	}
}

static void	fill_maptile(t_game *game, t_display *mlx, int x, int y)
{
	int	axis[2];
	int	pixel;
	int color;

	if (game->map[y][x] == '3')
		color = GREEN;
	else
		color = WHITE;
	x = x * TILE_SIZE;
	y = y * TILE_SIZE;
	axis[X] = 0;
	while (axis[X] < TILE_SIZE)
	{
		axis[Y] = 0;
		while (axis[Y] < TILE_SIZE)
		{
			pixel = (axis[Y] + y) * (WIN_WIDTH * 4) \
						+ (axis[X] + x) * 4;
			set_color(&mlx->img.address[pixel], \
				mlx->img.endian, color, 1);
			axis[Y]++;
		}
		axis[X]++;
	}
}

void	draw_maptiles(t_game *game, t_display *mlx)
{
	int	axis[2];

	axis[X] = 0;
	while (axis[X] < game->map_height)
	{
		axis[Y] = 0;
		while (axis[Y] < game->map_width)
		{
			if (game->map[axis[X]][axis[Y]] == '1' \
					|| game->map[axis[X]][axis[Y]] == '3')
				fill_maptile(game, mlx, axis[Y], axis[X]);
			axis[Y]++;
		}
		axis[X]++;
	}
}
