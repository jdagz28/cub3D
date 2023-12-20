/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:57:26 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/18 00:39:13 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (display->mlx != 0)
		exit (1);
	display->window = mlx_new_window(display->mlx, WIN_WIDTH, \
										WIN_HEIGHT, "Cub3D");
	display->img.img = mlx_new_image(display->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}
