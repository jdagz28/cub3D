/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2Dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:44:29 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/19 00:55:30 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

void	draw_playerpos(t_display *mlx, t_player *player, int axis[2], \
						int radius)
{
	int	pixel;

	if (axis[X_AXIS] * axis[X_AXIS] + axis[Y_AXIS] \
			* axis[Y_AXIS] <= radius * radius)
	{
		pixel = (player->position.axis[Y_AXIS] + axis[Y_AXIS]) * (WIDTH * 4) \
					+ (player->position.axis[X_AXIS] + axis[X_AXIS]) * 4;
		set_color(&mlx->img.address[pixel], mlx->img.endian, RED, 1);
	}
}

void	spawn_player(t_display *mlx)
{
	t_player	player;
	int			axis[2];
	int			radius;

	radius = 10;
	player.position = create_point(WIDTH / 2, HEIGHT / 2);
	player.direction = create_point(0, -1);
	axis[X_AXIS] = -radius;
	while (axis[X_AXIS] <= radius)
	{
		axis[Y_AXIS] = -radius;
		while (axis[Y_AXIS] <= radius)
		{
			draw_playerpos(mlx, &player, axis, radius);
			axis[Y_AXIS]++;
		}
		axis[X_AXIS]++;
	}
}

void	draw_map(t_gametest *game, t_display *mlx)
{
	draw_maptiles(game, mlx);
	draw_grids(mlx);
	spawn_player(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
