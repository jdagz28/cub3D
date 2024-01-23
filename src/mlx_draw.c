/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:54:52 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/23 19:23:05 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image_data *img, t_point pixel)
{
	int	mypixel;

	if (pixel.axis[X] >= WIN_WIDTH || pixel.axis[Y] \
		>= WIN_HEIGHT || pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return ;
	mypixel = ((int)pixel.axis[Y] * WIN_WIDTH * 4)
		+ ((int)pixel.axis[X] * 4);
	set_color(&img->address[mypixel], \
			img->endian, pixel.color, 0);
}
