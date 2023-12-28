/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2Dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:44:29 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/28 03:15:59 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

float	deg2rad(float degrees)
{
	return (degrees * (M_PI / 180));
}

void	draw_playerpos(t_display *mlx, t_player *player, \
							int axis[2], int radius)
{
	int	pixel;
	int	new_axis[2];

	new_axis[X_AXIS] = player->position.axis[X_AXIS] + axis[X_AXIS];
	new_axis[Y_AXIS] = player->position.axis[Y_AXIS] + axis[Y_AXIS];
	if (new_axis[X_AXIS] >= 0 && new_axis[X_AXIS] < WIDTH \
		&& new_axis[Y_AXIS] >= 0 && new_axis[Y_AXIS] < HEIGHT && \
		axis[X_AXIS] * axis[X_AXIS] + axis[Y_AXIS] * axis[Y_AXIS] \
		<= radius * radius)
	{
		pixel = new_axis[Y_AXIS] * (WIDTH * 4) + new_axis[X_AXIS] * 4;
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

void	update_player_front(t_player *player)
{
	player->front.dir[X_AXIS] = cos(player->angle) * 5;
	player->front.dir[Y_AXIS] = sin(player->angle) * 5;
}

void	init_player(t_player *player)
{
	player->position = create_point(WIDTH / 2, HEIGHT / 2);
	player->angle = M_PI / 2;
	update_player_front(player);
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
