/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:57:26 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/18 02:59:55 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_display *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (EXIT_FAILURE);
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (mlx->window == NULL)
		return (EXIT_FAILURE);
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img == NULL)
		return (EXIT_FAILURE);
	mlx->img.address = mlx_get_data_addr(mlx->img.img, \
		&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	return (0);
}
