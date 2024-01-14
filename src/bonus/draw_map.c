/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:27:39 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/08 23:39:36 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_game *game)
{
	ft_bzero(game->display.img.address, WIN_WIDTH * WIN_HEIGHT * 4);
	draw_ray(game);
	mlx_put_image_to_window(game->display.mlx, \
		game->display.window, game->display.img.img, 0, 0);
	return (0);
}

