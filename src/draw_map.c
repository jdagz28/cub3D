/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:27:39 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/03 14:57:14 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_gametest *game)
{
	ft_bzero(game->display.img.address, WIDTH * HEIGHT * 4);
	draw_minimap(game);
	draw_ray(game);
	draw_direction_dda(&game->display.img, game->player.position, \
							game->player.front);
	mlx_put_image_to_window(game->display.mlx, \
		game->display.window, game->display.img.img, 0, 0);
	return (0);
}

