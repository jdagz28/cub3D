/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:57:26 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 10:26:17 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_display *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit (1);
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.address = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}
