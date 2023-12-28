/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays2Dmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:36:23 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/28 21:24:51 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

void	draw_rays(t_gametest *game)
{
	int r, mx, my, mp, dof; 
	float r_x, r_y, r_angle, xo, yo;
	float aTan;

	r = -1;
	r_angle = game->player.angle;
	//Check Horizontal Lines
	while (++r < 1)
	{
		dof = 0;
		aTan = -1 / tan(r_angle);
		if (r_angle > M_PI)
		{
			r_y = (((int)game->player.position.axis[Y] >> 6) << 6) - 0.0001;
			r_x = (game->player.position.axis[Y] - r_y) * aTan + game->player.position.axis[X];
			yo = -64;
			xo = -yo * aTan;
		}
		if (r_angle < M_PI)
		{
			r_y = (((int)game->player.position.axis[Y] >> 6) << 6) + 64;
			r_x = (game->player.position.axis[Y] - r_y) * aTan + game->player.position.axis[X];
			yo = 64;
			xo =-yo *aTan;
		}
		if (r_angle == 0 || r_angle == M_PI)
		{
			r_x = game->player.position.axis[X];
			r_y = game->player.position.axis[Y];
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)r_x >> 6;
			my =(int)(r_y) >> 6;
			mp = my * WIDTH + mx;
			if (mp < HEIGHT * WIDTH && game->map[mp / ROWS][mp % COLS] == 1)
				dof = 8;
			else
			{
				r_x += xo;
				r_y += yo;
				dof += 1;
			}
		}
		t_point end = create_point(r_x, r_y);
		end.color = GREEN;
		draw_line_dda(&game->display.img, game->player.position, end);
	}
}
