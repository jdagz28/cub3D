/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:01:56 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/29 01:23:12 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

void	draw_direction_dda(t_image_data *img, t_point start, t_vector front)
{
	int		steps;
	t_point	pixel;
	float	indices[2];
	float	end[2];

	end[X] = start.axis[X] + front.dir[X] * 10;
	end[Y] = start.axis[Y] + front.dir[Y] * 10;
	if (fabsf(end[X] - start.axis[X]) \
			> fabsf(end[Y] - start.axis[Y]))
		steps = fabsf(end[X] - start.axis[X]);
	else
		steps = fabsf(end[Y] - start.axis[Y]);
	indices[X] = (end[X] - start.axis[X]) / steps;
	indices[Y] = (end[Y] - start.axis[Y]) / steps;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	pixel.color = RED;
	while (steps--)
	{
		my_mlx_pixel_put(img, pixel);
		pixel.axis[X] += indices[X];
		pixel.axis[Y] += indices[Y];
	}
}


void	draw_line_dda(t_image_data *img, t_point start, t_point end)
{
	int		steps;
	t_point	pixel;
	float	indices[2];

	if (fabsf(end.axis[X] - start.axis[X]) \
			> fabsf(end.axis[Y] - start.axis[Y]))
		steps = fabsf(end.axis[X] - start.axis[X]);
	else
		steps = fabsf(end.axis[Y] - start.axis[Y]);
	indices[X] = (end.axis[X] - start.axis[X]) / steps;
	indices[Y] = (end.axis[Y] - start.axis[Y]) / steps;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	pixel.color = end.color;
	while (steps--)
	{
		my_mlx_pixel_put(img, pixel);
		pixel.axis[X] += indices[X];
		pixel.axis[Y] += indices[Y];
	}
}

void	draw_grids(t_display *mlx)
{
	int		axis[2];
	t_point	end;

	axis[Y] = 0;
	while (axis[Y] < WIDTH)
	{
		end = create_point(axis[Y], HEIGHT);
		end.color = GRAY;
		draw_line_dda(&mlx->img, create_point(axis[Y], 0), end);
		axis[Y] += TILE_SIZE;
	}
	axis[X] = 0;
	while (axis[X] < HEIGHT)
	{
		end = create_point(WIDTH, axis[X]);
		end.color = GRAY;
		draw_line_dda(&mlx->img, create_point(0, axis[X]), end);
		axis[X] += TILE_SIZE;
	}
}

t_point	create_point(float x, float y)
{
	t_point	point;

	point.axis[X] = x;
	point.axis[Y] = y;
	return (point);
}

t_vector	create_vector(float x, float y)
{
	t_vector	vector;

	vector.dir[X] = x;
	vector.dir[Y] = y;
	return (vector);
}
