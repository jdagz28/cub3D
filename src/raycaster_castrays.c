/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_castrays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:31:25 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/08 23:07:28 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_raywallhit(t_game *game)
{
	if (game->map[game->ray.map_intersect_y][game->ray.map_intersect_x] == '1')
		return (1);
	return (0);
}

void	cast_horizontal_rays(t_game *game)
{
	game->ray.dof = 0;
	while (game->ray.dof < 20)
	{
		game->ray.map_intersect_x = (int)game->ray.x / TILE_SIZE;
		if (game->ray.map_intersect_x >= game->map_width)
			game->ray.map_intersect_x = game->map_width - 1;
		if (game->ray.map_intersect_x < 0)
			game->ray.map_intersect_x = 0;
		game->ray.map_intersect_y = (int)game->ray.y / TILE_SIZE;
		if (game->ray.map_intersect_y >= game->map_height)
			game->ray.map_intersect_y = game->map_height - 1;
		if (game->ray.map_intersect_y < 0)
			game->ray.map_intersect_y = 0;
		if (check_raywallhit(game) == 1)
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

void	cast_vertical_rays(t_game *game)
{
	game->ray.dof = 0;
	while (game->ray.dof < 20)
	{
		game->ray.map_intersect_x = (int)game->ray.x / TILE_SIZE;
		if (game->ray.map_intersect_x >= game->map_width)
			game->ray.map_intersect_x = game->map_width - 1;
		if (game->ray.map_intersect_x < 0)
			game->ray.map_intersect_x = 0;
		game->ray.map_intersect_y = (int)game->ray.y / TILE_SIZE;
		if (game->ray.map_intersect_y >= game->map_height)
			game->ray.map_intersect_y = game->map_height - 1;
		if (game->ray.map_intersect_y < 0)
			game->ray.map_intersect_y = 0;
		if (check_raywallhit(game) == 1)
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
