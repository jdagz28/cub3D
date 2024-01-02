/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:24:06 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/02 23:38:36 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map2dtest.h"

float	fix_fisheye(t_gametest *game)
{
	float	angle;

	angle = game->player.angle - game->ray.angle;
	if (angle < 0)
		return (angle += 2 * M_PI);
	if (angle > 2 * M_PI)
		return (angle -= 2 * M_PI);
	return (angle);
}

void	draw_wall(t_gametest *game, int i, int j)
{
	int		counter;
	t_point	pixel;

	counter = -1;
	while (++counter < game->ray.height)
	{
		pixel = create_point(i, j + counter);
		pixel.color = RED;
		my_mlx_pixel_put(&game->display.img, pixel);
	}
}

void	draw_3d(t_gametest *game, int raynum)
{
	int	i;

	i = WIDTH - 1 - raynum * RAYCOUNT / 2;
	if (game->ray.dist_h < game->ray.dist_v)
		game->ray.dist = game->ray.dist_h;
	else
		game->ray.dist = game->ray.dist_v;
	game->ray.dist = game->ray.dist * cos(fix_fisheye(game));
	game->ray.height = (TILE_SIZE * HEIGHT) / game->ray.dist;
	game->ray.start = HEIGHT / 2 - game->ray.height / 2;
	game->ray.end = HEIGHT / 2 + game->ray.height / 2;
	draw_wall(game, i, game->ray.start);
}