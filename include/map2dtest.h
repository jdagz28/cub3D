/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2dtest.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:47:12 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/28 20:51:30 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP2DTEST_H
# define MAP2DTEST_H

# define TILE_SIZE 60
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define MOVE_SPEED 10
# include "cub3d.h"
# include "struct.h"

typedef struct s_gametest
{
	t_display	display;
	t_player	player;
	t_texture	texture;
	//int floor_color;
	//int ceiling_color;
	int			map_width;
	int			map_height;
	int			map[ROWS][COLS];
	int			fd;
}	t_gametest;

void	draw_playerpos(t_display *mlx, t_player *player, int axis[2], \
						int radius);
void	draw_player(t_gametest *game);
void	init_player(t_player *player);
int		draw_map(t_gametest *game);
void	draw_line_dda(t_image_data *img, t_point start, t_point end);
void	draw_grids(t_display *mlx);
t_point	create_point(float x, float y);
t_vector	create_vector(float x, float y);
void	fill_maptile(t_display *mlx, int x, int y);
void	draw_maptiles(t_gametest *game, t_display *mlx);
void	set_color(char *buffer, int endian, int color, int alpha);
void	draw_rays2dmap(t_display *mlx, t_point player_pos, t_point dir);
void draw_direction_dda(t_image_data *img, t_point start, t_vector end);
void	update_player_front(t_player *player);
void	draw_rays(t_gametest *game);
#endif