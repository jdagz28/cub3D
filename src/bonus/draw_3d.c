/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:24:06 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/14 20:46:31 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "enums.h"

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

static int	get_direction(t_game *game)
{
	if (game->ray.hit == 1)
	{
		if (game->ray.angle > M_PI)
			return (SOUTH);
		else
			return (NORTH);
	}
	else if (game->ray.angle > M_PI_2 && game->ray.angle < M_PI_3)
		return (WEST);
	else
		return (EAST);
}

static float	check_rayhit(t_game *game, float x)
{
	if (game->ray.hit == 1)
	{
		x = (int)(game->ray.x / 3) % TILE_SIZE;
		if (get_direction(game) == SOUTH)
			return (TILE_SIZE - x - 1);
	}
	else
	{
		x = (int)(game->ray.y / 2) % TILE_SIZE;
		if (get_direction(game) == WEST)
			return (TILE_SIZE - x - 1);
	}
	return (x);
}

static int	get_texturecolor(t_game *game, t_walltexture *texture)
{
	int	pos;
	int	pixel_color;

	pos = (int)texture->y * TILE_SIZE + texture->x;
	if (pos > (TILE_SIZE * TILE_SIZE))
		pos = 4095;
	if (get_direction(game) == NORTH)
		pixel_color = game->texture.n_texture[pos];
	else if (get_direction(game) == SOUTH)
		pixel_color = game->texture.s_texture[pos];
	else if (get_direction(game) == EAST)
		pixel_color = game->texture.e_texture[pos];
	else if (get_direction(game) == WEST)
		pixel_color = game->texture.w_texture[pos];
	return (pixel_color);
}

static void	draw_wall(t_game *game, int i, int j)
{
	int				counter;
	t_point			pixel;
	t_walltexture	texture;

	texture.y_step = TILE_SIZE / game->ray.height;
	texture.y_offset = 1;
	if (game->ray.height > WIN_HEIGHT)
	{
		texture.y_offset = (game->ray.height - WIN_HEIGHT) / 2;
		game->ray.height = WIN_HEIGHT;
	}
	texture.y = texture.y_offset * texture.y_step;
	texture.x = 0;
	texture.x = check_rayhit(game, texture.x);
	counter = -1;
	while (++counter < game->ray.height)
	{
		pixel = create_point(i, j + counter);
		pixel.color = get_texturecolor(game, &texture);
		my_mlx_pixel_put(&game->display.img, pixel);
		texture.y += texture.y_step;
	}
}

void	draw_3d(t_game *game, int raynum)
{
	int		j;
	t_point	pixel;

	if (game->ray.dist_h < game->ray.dist_v)
		game->ray.dist = game->ray.dist_h;
	else
		game->ray.dist = game->ray.dist_v;
	game->ray.dist = game->ray.dist * cos(fix_fisheye(game));
	game->ray.height = (TILE_SIZE * WIN_HEIGHT) / game->ray.dist;
	game->ray.start = WIN_HEIGHT / 2 - game->ray.height / 2;
	game->ray.end = WIN_HEIGHT / 2 + game->ray.height / 2;
	j = -1;
	while (++j < game->ray.start)
	{
		pixel = create_point(raynum, j);
		pixel.color = game->ceiling_color;
		my_mlx_pixel_put(&game->display.img, pixel);
	}
	j--;
	draw_wall(game, raynum, j);
	j = game->ray.end - 2;
	while (++j < WIN_HEIGHT)
	{
		pixel = create_point(raynum, j);
		pixel.color = game->floor_color;
		my_mlx_pixel_put(&game->display.img, pixel);
	}
}
