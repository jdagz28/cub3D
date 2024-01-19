/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vectorpoint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:28:29 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/19 09:20:12 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	create_point(float x, float y, int color)
{
	t_point	point;

	point.axis[X] = x;
	point.axis[Y] = y;
	point.color = color;
	return (point);
}

t_vector	create_vector(float x, float y)
{
	t_vector	vector;

	vector.dir[X] = x;
	vector.dir[Y] = y;
	return (vector);
}
