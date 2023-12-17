/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2023/12/18 00:58:28 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

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
}

void	fill_maptile(t_display *mlx, int x, int y)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx->img.address[(y + i) * WIDTH + x + j] = 255;
			j++;
		}
		i++;
	}
}

void	draw_maptiles(t_gametest *game, t_display *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 1)
				fill_maptile(mlx, j, i);
			j++;
		}
		i++;
	}	
}

void	draw_map(t_gametest *game, t_display *mlx)
{
	draw_maptiles(game, mlx);
	// draw_grid(game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
int	main(void)
{
	t_gametest		game;
	t_display		mlx;
	t_image_data	img;

	game.map_width = 15;
	game.map_height = 11;
	init_testmap(&game);

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3D");

	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.address = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	mlx.img = img;
	draw_map(&game, &mlx);
	mlx_loop(mlx.mlx);

	return (0);
}


