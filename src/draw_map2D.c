/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/18 14:53:49 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define X_AXIS 0
#define Y_AXIS 1

#define TILE_SIZE 60
#define ROWS 11
#define COLS 15
#define WIDTH COLS * TILE_SIZE
#define HEIGHT ROWS * TILE_SIZE

typedef struct s_gametest
{
	t_player	player;
	t_texture	texture;
	//int floor_color;
	//int ceiling_color;
	int			map_width;
	int			map_height;
	int			map[ROWS][COLS];
	int			fd;
}	t_gametest;

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

void	init_testmap(t_gametest *game)
{
	int	map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	ft_memcpy(game->map, map, sizeof(int) * ROWS * COLS);
	game->map_width = COLS;
	game->map_height = ROWS;
}

void	fill_maptile(t_display *mlx, int x, int y)
{
	int	axis[2];
	int	pixel;

	x = x * TILE_SIZE;
	y = y * TILE_SIZE;
	axis[X_AXIS] = 0;
	while (axis[X_AXIS] < TILE_SIZE)
	{
		axis[Y_AXIS] = 0;
		while (axis[Y_AXIS] < TILE_SIZE)
		{
			pixel = (axis[Y_AXIS] + y) * (WIDTH * 4) \
						+ (axis[X_AXIS] + x) * 4;
			set_color(&mlx->img.address[pixel], \
				mlx->img.endian, WHITE, 1);
			axis[Y_AXIS]++;
		}
		axis[X_AXIS]++;
	}
}

void	draw_maptiles(t_gametest *game, t_display *mlx)
{
	int	axis[2];

	axis[X_AXIS] = 0;
	while (axis[X_AXIS] < game->map_height)
	{
		axis[Y_AXIS] = 0;
		while (axis[Y_AXIS] < game->map_width)
		{
			if (game->map[axis[X_AXIS]][axis[Y_AXIS]] == 1)
				fill_maptile(mlx, axis[Y_AXIS], axis[X_AXIS]);
			axis[Y_AXIS]++;
		}
		axis[X_AXIS]++;
	}	
}

void	draw_map(t_gametest *game, t_display *mlx)
{
	draw_maptiles(game, mlx);
	//draw_grids(game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
int	main(void)
{
	t_gametest		game;
	t_display		mlx;

	init_testmap(&game);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3D");
	mlx.img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.address = mlx_get_data_addr(mlx.img.img,
			&mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	draw_map(&game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
