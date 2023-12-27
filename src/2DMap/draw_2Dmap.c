/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2Dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:44:29 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/27 01:50:34 by jdagoy           ###   ########.fr       */
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

void	draw_player(t_gametest *game)
{
	int			axis[2];
	int			radius;

	radius = 10;
	axis[X_AXIS] = -radius;
	while (axis[X_AXIS] <= radius)
	{
		axis[Y_AXIS] = -radius;
		while (axis[Y_AXIS] <= radius)
		{
			draw_playerpos(&game->display, &game->player, axis, radius);
			axis[Y_AXIS]++;
		}
		axis[X_AXIS]++;
	}
	draw_direction_dda(&game->display.img, game->player.position, game->player.front);
}

void	init_player(t_player *player)
{
	player->position = create_point(WIDTH / 2, HEIGHT / 2);
	player->angle = 90;
	player->front = create_vector(cos(player->angle) * 5, \
						sin(player->angle) * 5);

}

int	draw_map(t_gametest *game)
{
	ft_bzero(game->display.img.address, WIDTH * HEIGHT * 4);
	draw_maptiles(game, &game->display);
	draw_grids(&game->display);
	draw_player(game);
	mlx_put_image_to_window(game->display.mlx, \
		game->display.window, game->display.img.img, 0, 0);
	return (0);
}
