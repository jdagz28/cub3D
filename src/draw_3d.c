/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:24:06 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/05 04:06:46 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	fix_fisheye(t_game *game)
{
	float	angle;

	angle = game->player.angle - game->ray.angle;
	if (angle < 0)
		return (angle += 2 * M_PI);
	if (angle > 2 * M_PI)
		return (angle -= 2 * M_PI);
	return (angle);
}

static float	get_direction(t_game *game)
{
	if (game->ray.hit == 1)
	{
		if (game->ray.angle > M_PI)
			return (South);
		else
			return (North);
	}
	else
	{
		if (game->ray.angle > M_PI_2 && game->ray.angle < M_PI_3)
			return (West);
		else
			return (East);
	}
}

static float	check_rayhit(t_game *game, float x)
{
	if (game->ray.hit == 1)
	{
		x = (int)(game->ray.x / 3) % TILE_SIZE;
		if (get_direction(game) == South)
			return (TILE_SIZE - x - 1);
	}
	else
	{
		x = (int)(game->ray.y / 2) % TILE_SIZE;
		if (get_direction(game) == West)
			return (TILE_SIZE - x - 1);
	}
}

static void	draw_wall(t_game *game, int i, int j)
{
	int				counter;
	// t_point			pixel;
	t_walltexture	texture;

	texture.y_step = TILE_SIZE / game->ray.height;
	texture.y_step = 1;
	if (game->ray.height > game->window_height)
	{
		texture.y_offset = (game->ray.height - game->window_height) / 2;
		game->ray.height = game->window_height;
	}
	texture.y = texture.y_offset * texture.y_step;
	texture.x = 0;
	texture.x = check_rayhit(game, texture.x);
	counter = -1;
	while (++counter < game->ray.height)
	{
		// pixel = create_point(i, j + counter);
		// pixel.color = game->ray.color;
		my_mlx_pixel_put(game, &game->display.img, pixel);
	}
}

void	draw_3d(t_game *game, int raynum)
{
	int		i;
	int		j;
	t_point	pixel;

	i = game->window_width - 1 - raynum * FOV * 0.95; //0.95 factor to render right side of the window.
	if (game->ray.dist_h < game->ray.dist_v)
		game->ray.dist = game->ray.dist_h;
	else
		game->ray.dist = game->ray.dist_v;
	game->ray.dist = game->ray.dist * cos(fix_fisheye(game));
	game->ray.height = (TILE_SIZE * game->window_height) / game->ray.dist;
	game->ray.start = game->window_height / 2 - game->ray.height / 2;
	game->ray.end = game->window_height / 2 + game->ray.height / 2;
	j = -1;
	while (++j < game->ray.start)
	{
		pixel = create_point(i, j);
		pixel.color = game->ceiling_color;
		my_mlx_pixel_put(game, &game->display.img, pixel);
	}
	j--;
	draw_wall(game, i, j);
	j = game->ray.end - 2;
	while (++ j < game->window_height)
	{
		pixel = create_point(i, j);
		pixel.color = game->floor_color;
		my_mlx_pixel_put(game, &game->display.img, pixel);
	}
}
