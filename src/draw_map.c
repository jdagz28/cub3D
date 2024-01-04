/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:27:39 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/04 03:19:37 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_game *game)
{
	ft_bzero(game->display.img.address, game->window_width \
					* game->window_height * 4);
	draw_minimap(game);
	draw_ray(game);
	draw_direction_dda(game, &game->display.img, game->player.position, \
							game->player.front);
	mlx_put_image_to_window(game->display.mlx, \
		game->display.window, game->display.img.img, 0, 0);
	return (0);
}

