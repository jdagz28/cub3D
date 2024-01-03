/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2Dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:44:29 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/02 23:33:35 by jdagoy           ###   ########.fr       */
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

void	draw_player(t_gametest *game)
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

void	update_player_front(t_player *player)
{
	player->front.dir[X] = cos(player->angle) * 5;
	player->front.dir[Y] = (sin(player->angle) * 5) * -1;
}

void	init_player(t_player *player)
{
	player->position = create_point((WIDTH / 2) / 2, HEIGHT / 2);
	player->angle = M_PI / 2;
	update_player_front(player);
}

int	draw_map(t_gametest *game)
{
	ft_bzero(game->display.img.address, WIDTH * HEIGHT * 4);
	draw_maptiles(game, &game->display);
	draw_grids(&game->display);
	draw_player(game);
	// init_ray(game);
	draw_ray(game);
	draw_direction_dda(&game->display.img, game->player.position, game->player.front);
	mlx_put_image_to_window(game->display.mlx, \
		game->display.window, game->display.img.img, 0, 0);
	return (0);
}
