/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:52 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/29 00:58:11 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image_data *img, t_point pixel)
{
	int	mypixel;

	if (pixel.axis[X] >= WIDTH || pixel.axis[Y] \
		>= HEIGHT || pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return ;
	mypixel = ((int)pixel.axis[Y] * WIDTH * 4)
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
