/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:36:23 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/29 00:40:17 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

void	cast_horizontal_rays(t_gametest *game)
{
	game->ray.dof = 0;
	while (game->ray.dof < 20)
	{
		game->ray.map_intersect_x = (int)game->ray.x / 64;
		if (game->ray.map_intersect_x >= (int)game->map_width)
			game->ray.map_intersect_x = game->map_width - 1;
		if (game->ray)
	}
}

void	set_horizontal_angle(t_gametest *game, float arc_tan)
{
	if (game->ray.angle < M_PI)
	{
		game->ray.y = ((int)game->player.position.axis[Y] / 64) * 64 - 0.0001;
		game->ray.x = (game->player.position.axis[Y] - game->ray.y) * \
						arc_tan + game->player.position.axis[X];
		game->ray.step_y = -64;
		game->ray.step_x = -game->ray.step_y * arc_tan;
	}
	else if (game->ray.angle > M_PI)
	{
		game->ray.y = ((int)game->player.position.axis[Y] / 64) * 64 + 64;
		game->ray.x = (game->player.position.axis[Y] - game->ray.y) * \
						arc_tan + game->player.position.axis[X];
		game->ray.step_y = 64;
		game->ray.step_x = -game->ray.step_y * arc_tan;
	}
	if (game->ray.angle == 0 || game->ray.angle == M_PI)
	{
		game->ray.x = game->player.position.axis[X];
		game->ray.y = game->player.position.axis[Y];
		game->ray.dof = game->map_height * game->map_width;
	}
}

void	init_ray(t_gametest *game)
{
	float	tangent;
	float	arc_tan;

	arc_tan = -1 / tan(game->player.angle);
	game->ray.dist_h = -1;
	game->ray.x = game->player.position.axis[X];
	game->ray.y = game->player.position.axis[Y];
	set_horizontal_angle(game, arc_tan);
	cast_horizontal_rays(game);
}

void	draw_ray(t_gametest *game)
{
	int	i;

	i = 0;
	game->ray.angle = game->player.angle - FOV / 2;
	if (game->ray.angle < 0)
		game->ray.angle += 2 * M_PI;
	if (game->ray.angle > 2 * M_PI)
		game->ray.angle -= 2 * M_PI;
	while (i < WIDTH)
	{
		init_ray(game);
		game->ray.angle = game->player.angle + FOV / 2 - FOV * i / WIDTH;
		if (game->ray.angle < 0)
			game->ray.angle += 2 * M_PI;
		if (game->ray.angle > 2 * M_PI)
			game->ray.angle -= 2 * M_PI;
	}
}
