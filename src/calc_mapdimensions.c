/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mapdimensions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:37:19 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/17 12:37:42 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	calc_mapdimensions(t_game *game)
{
	int	i;
	int	temp;
	int	width;
	int	height;

	i = -1;
	temp = 0;
	width = 0;
	height = 0;
	while (game->map[height] != NULL)
		height++;
	game->map_height = height;
	while (++i < height)
	{
		temp = ft_strlen(game->map[i]);
		if (temp > width)
			width = temp;
	}
	game->map_width = width;
}
