/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/18 15:17:30 by jdagoy           ###   ########.fr       */
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

typedef struct s_point
{
	float	axis[2];
}	t_point;

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

static void	draw_line_dda(t_image_data *img, t_point start, t_point end)
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

t_point	create_point(int x, int y)
{
	t_point	point;

	point.axis[X_AXIS] = x;
	point.axis[Y_AXIS] = y;
	return (point);
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
	draw_grids(mlx);
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
