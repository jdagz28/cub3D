/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2dtest.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:47:12 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/03 14:58:33 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP2DTEST_H
# define MAP2DTEST_H

# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE * 2
# define HEIGHT ROWS * TILE_SIZE
# include "cub3d.h"
# include "struct.h"

typedef struct s_gametest
{
	t_display	display;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	//int floor_color;
	//int ceiling_color;
	int			map_width;
	int			map_height;
	int			map[ROWS][COLS];
	int			fd;
}	t_gametest;


#endif