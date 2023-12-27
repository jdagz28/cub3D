/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:01:56 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/27 01:56:41 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

void	draw_direction_dda(t_image_data *img, t_point start, t_vector end)
{
	int		steps;
	t_point	pixel;
	float	indices[2];

	if (fabsf(end.dir[X_AXIS] - start.axis[X_AXIS]) \
			> fabsf(end.dir[Y_AXIS] - start.axis[Y_AXIS]))
		steps = fabsf(end.dir[X_AXIS] - start.axis[X_AXIS]);
	else
		steps = fabsf(end.dir[Y_AXIS] - start.axis[Y_AXIS]);
	indices[X_AXIS] = (end.dir[X_AXIS] - start.axis[X_AXIS]) / (float)steps;
	indices[Y_AXIS] = (end.dir[Y_AXIS] - start.axis[Y_AXIS]) / (float)steps;
	pixel.axis[X_AXIS] = start.axis[X_AXIS];
	pixel.axis[Y_AXIS] = start.axis[Y_AXIS];
	while (steps--)
	{
		my_mlx_pixel_put(img, pixel.axis[X_AXIS], pixel.axis[Y_AXIS], RED);
		pixel.axis[X_AXIS] += indices[X_AXIS];
		pixel.axis[Y_AXIS] += indices[Y_AXIS];
	}
}



void	draw_line_dda(t_image_data *img, t_point start, t_point end)
{
	int		steps;
	t_point	pixel;
	float	indices[2];

	if (fabsf(end.axis[X_AXIS] - start.axis[X_AXIS]) \
			> fabsf(end.axis[Y_AXIS] - start.axis[Y_AXIS]))
		steps = fabsf(end.axis[X_AXIS] - start.axis[X_AXIS]);
	else
		steps = fabsf(end.axis[Y_AXIS] - start.axis[Y_AXIS]);
	indices[X_AXIS] = (end.axis[X_AXIS] - start.axis[X_AXIS]) / (float)steps;
	indices[Y_AXIS] = (end.axis[Y_AXIS] - start.axis[Y_AXIS]) / (float)steps;
	pixel.axis[X_AXIS] = start.axis[X_AXIS];
	pixel.axis[Y_AXIS] = start.axis[Y_AXIS];
	while (steps--)
	{
		my_mlx_pixel_put(img, pixel.axis[X_AXIS], pixel.axis[Y_AXIS], RED);
		pixel.axis[X_AXIS] += indices[X_AXIS];
		pixel.axis[Y_AXIS] += indices[Y_AXIS];
	}
}

void	draw_grids(t_display *mlx)
{
	int	axis[2];

	axis[Y_AXIS] = 0;
	while (axis[Y_AXIS] < WIDTH)
	{
		draw_line_dda(&mlx->img, create_point(axis[Y_AXIS], 0), \
			create_point(axis[Y_AXIS], HEIGHT));
		axis[Y_AXIS] += TILE_SIZE;
	}
	axis[X_AXIS] = 0;
	while (axis[X_AXIS] < HEIGHT)
	{
		draw_line_dda(&mlx->img, create_point(0, axis[X_AXIS]), \
			create_point(WIDTH, axis[X_AXIS]));
		axis[X_AXIS] += TILE_SIZE;
	}
}

t_point	create_point(int x, int y)
{
	t_point	point;

	point.axis[X_AXIS] = x;
	point.axis[Y_AXIS] = y;
	return (point);
}

t_vector	create_vector(int x, int y)
{
	t_vector	vector;

	vector.dir[X_AXIS] = x;
	vector.dir[Y_AXIS] = y;
	return (vector);
}
