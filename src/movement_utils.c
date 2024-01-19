/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:03:23 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/19 20:59:18 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cal_side_direction(t_vector *front, t_vector *side)
{
	side->dir[X] = -front->dir[Y];
	side->dir[Y] = front->dir[X];
}

int	check_playerpos(t_game *game)
{
	game->player.array_x = (int)game->player.position.axis[X] / TILE_SIZE;
	game->player.array_y = (int)game->player.position.axis[Y] / TILE_SIZE;
	if (game->player.array_x < 0 || game->player.array_y < 0)
		return (0);
	return (1);
}

int	offset_check(t_game *game, char *type, int value)
{
	int	res;

	res = 0;
	if (value < 0)
		res = 0;
	else if (ft_strncmp(type, "add_x", ft_strlen(type)) == 0 || \
				ft_strncmp(type, "sub_x", ft_strlen(type)) == 0)
		res = game->map_width;
	else if (ft_strncmp(type, "add_y", ft_strlen(type)) == 0 || \
				ft_strncmp(type, "sub_y", ft_strlen(type)) == 0)
		res = game->map_height;
	return (res);
}
