/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:36:23 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/08 23:29:24 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static void	calculate_shading(t_game *game)
{
	if (game->ray.dist_h < game->ray.dist_v)
	{
		game->ray.shade = 0.5;
		game->ray.x = game->ray.h_x;
		game->ray.y = game->ray.h_y;
		game->ray.dist = game->ray.dist_h;
		game->ray.color = RED;
		game->ray.hit = 1;
	}
	else if (game->ray.dist_v < game->ray.dist_h)
	{
		game->ray.x = game->ray.v_x;
		game->ray.y = game->ray.v_y;
		game->ray.dist = game->ray.dist_v;
		game->ray.color = 0x9B0000;
		game->ray.hit = -1;
	}
}

static void	init_ray(t_game *game)
{
	float	tangent;
	float	arc_tan;

	arc_tan = 1 / tan(game->ray.angle);
	game->ray.dist_h = 10000000;
	game->ray.map_intersect_x = game->player.array_x;
	game->ray.map_intersect_y = game->player.array_y;
	set_horizontal_angle(game, arc_tan);
	cast_horizontal_rays(game);
	tangent = tan(game->ray.angle);
	game->ray.dist_v = 10000000;
	set_vertical_angle(game, tangent);
	cast_vertical_rays(game);
	calculate_shading(game);
}

void	draw_ray(t_game *game)
{
	int	i;

	i = -1;
	game->ray.angle = game->player.angle - FOV / 2;
	if (game->ray.angle < 0)
		game->ray.angle += 2 * M_PI;
	if (game->ray.angle > 2 * M_PI)
		game->ray.angle -= 2 * M_PI;
	while (++i < WIN_WIDTH)
	{
		init_ray(game);
		draw_3d(game, i);
		game->ray.angle = game->player.angle + FOV / 2 - \
							FOV * i / WIN_WIDTH;
		if (game->ray.angle < 0)
			game->ray.angle += 2 * M_PI;
		if (game->ray.angle > 2 * M_PI)
			game->ray.angle -= 2 * M_PI;
	}
}
