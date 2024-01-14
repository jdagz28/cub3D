/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_angles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:30:07 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/04 02:02:17 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_horizontal_angle(t_game *game, float arc_tan)
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

void	set_vertical_angle(t_game *game, float tangent)
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
