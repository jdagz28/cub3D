/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:52 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/04 03:21:24 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *game, t_image_data *img, t_point pixel)
{
	int	mypixel;

	if (pixel.axis[X] >= game->window_width || pixel.axis[Y] \
		>= game->window_height || pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return ;
	mypixel = ((int)pixel.axis[Y] * game->window_width * 4)
		+ ((int)pixel.axis[X] * 4);
	set_color(&img->address[mypixel], \
			img->endian, pixel.color, 0);
}

// void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->address + (y * data->line_length
// 			+ x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
