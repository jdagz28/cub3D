/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:36:23 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/03 13:48:04 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

float	get_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	cast_horizontal_rays(t_gametest *game)
{
	game->ray.dof = 0;
	while (game->ray.dof < 20)
	{
		game->ray.map_intersect_x = (int)game->ray.x / 64;
		if (game->ray.map_intersect_x >= game->map_width)
			game->ray.map_intersect_x = game->map_width - 1;
		if (game->ray.map_intersect_x < 0)
			game->ray.map_intersect_x = 0;
		game->ray.map_intersect_y = (int)game->ray.y / 64;
		if (game->ray.map_intersect_y >= game->map_height)
			game->ray.map_intersect_y = game->map_height - 1;
		if (game->ray.map_intersect_y < 0)
			game->ray.map_intersect_y = 0;
		if (game->map[game->ray.map_intersect_y][game->ray.map_intersect_x] == 1 \
			&& game->ray.map_intersect_y <= game->map_height && game->ray.map_intersect_x <= game->map_width)
		{
			game->ray.h_x = game->ray.x;
			game->ray.h_y = game->ray.y;
			game->ray.dist_h = get_distance(game->player.position.axis[X], \
					game->player.position.axis[Y], game->ray.x, game->ray.y);
			break ;
		}
		game->ray.x += game->ray.step_x;
		game->ray.y += game->ray.step_y;
		game->ray.dof++;
	}
}
void	cast_vertical_rays(t_gametest *game)
{
	game->ray.dof = 0;
	while (game->ray.dof < 20)
	{
		game->ray.map_intersect_x = (int)game->ray.x / 64;
		if (game->ray.map_intersect_x >= game->map_width)
			game->ray.map_intersect_x = game->map_width - 1;
		if (game->ray.map_intersect_x < 0)
			game->ray.map_intersect_x = 0;
		game->ray.map_intersect_y = (int)game->ray.y / 64;
		if (game->ray.map_intersect_y >= game->map_height)
			game->ray.map_intersect_y = game->map_height - 1;
		if (game->ray.map_intersect_y < 0)
			game->ray.map_intersect_y = 0;
		if (game->map[game->ray.map_intersect_y][game->ray.map_intersect_x] == 1 \
			&& game->ray.map_intersect_y <= game->map_height && game->ray.map_intersect_x <= game->map_width)
		{
			game->ray.v_x = game->ray.x;
			game->ray.v_y = game->ray.y;
			game->ray.dist_v = get_distance(game->player.position.axis[X], \
					game->player.position.axis[Y], game->ray.x, game->ray.y);
			break ;
		}
		game->ray.x += game->ray.step_x;
		game->ray.y += game->ray.step_y;
		game->ray.dof++;
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
	else if (game->ray.angle == 0 || game->ray.angle == M_PI)
	{
		game->ray.x = game->player.position.axis[X];
		game->ray.y = game->player.position.axis[Y];
		game->ray.dof = game->map_height * game->map_width;
	}
}

void	set_vertical_angle(t_gametest *game, float tangent)
{
	if (game->ray.angle > M_PI_2 && game->ray.angle < M_PI_3)
	{
		game->ray.x = ((int)game->player.position.axis[X] / 64) * 64 - 0.0001;
		game->ray.y = (game->player.position.axis[X] - game->ray.x) \
						* tangent + game->player.position.axis[Y];
		game->ray.step_x = -64;
		game->ray.step_y = -game->ray.step_x * tangent;
	}
	else if (game->ray.angle < M_PI_2 || game->ray.angle > M_PI_3)
	{
		game->ray.x = ((int)game->player.position.axis[X] / 64) * 64 + 64;
		game->ray.y = (game->player.position.axis[X] - game->ray.x) \
						* tangent + game->player.position.axis[Y];
		game->ray.step_x = 64;
		game->ray.step_y = -game->ray.step_x * tangent;
	}
	else if (game->ray.angle == 0 || game->ray.angle == M_PI)
	{
		game->ray.x = game->player.position.axis[X];
		game->ray.y = game->player.position.axis[Y];
		game->ray.dof = game->map_height * game->map_width;
	}
}

void	calculate_shading(t_gametest * game)
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

void	init_ray(t_gametest *game)
{
	float	tangent;
	float	arc_tan;
	// t_point	end_x;
	// t_point	end_y;
	t_point	end;

	arc_tan = 1 / tan(game->ray.angle);
	game->ray.dist_h = 10000000;
	game->ray.x = game->player.position.axis[X];
	game->ray.y = game->player.position.axis[Y];
	set_horizontal_angle(game, arc_tan);
	cast_horizontal_rays(game);
	// end_x = create_point(game->ray.h_x, game->ray.h_y);
	// end_x.color = GREEN;
	// draw_line_dda(&game->display.img, game->player.position, end_x);
	tangent = tan(game->ray.angle);
	game->ray.dist_v = 10000000;
	set_vertical_angle(game, tangent);
	cast_vertical_rays(game);
	// end_y = create_point(game->ray.v_x, game->ray.v_y);
	// end_y.color = RED;
	// draw_line_dda(&game->display.img, game->player.position, end_y);
	calculate_shading(game);
	end = create_point(game->ray.x, game->ray.y);
	end.color = GREEN;
	draw_line_dda(&game->display.img, game->player.position, end);
}

void	draw_ray(t_gametest *game)
{
	int	i;

	i = -1;
	game->ray.angle = game->player.angle - FOV / 2;
	if (game->ray.angle < 0)
		game->ray.angle += 2 * M_PI;
	if (game->ray.angle > 2 * M_PI)
		game->ray.angle -= 2 * M_PI;
	while (++i < WIDTH / 2)
	{
		init_ray(game);
		draw_3d(game, i);
		game->ray.angle = game->player.angle + FOV / 2 - FOV * i / (WIDTH / 2);
		if (game->ray.angle < 0)
			game->ray.angle += 2 * M_PI;
		if (game->ray.angle > 2 * M_PI)
			game->ray.angle -= 2 * M_PI;
	}
}
