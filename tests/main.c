/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 11:08:06 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	read_textures(t_game *game, t_display *mlx, char *texture_path, \
							char *dir)
{
	int	i;
	int	j;
	int	pos;

	mlx->img.img = mlx_xpm_file_to_image(mlx->mlx, texture_path, \
						&game->texture.width, &game->texture.height);
	mlx->img.add_itr = (int *)mlx_get_data_addr(mlx->img.img, \
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
		{
			pos = game->texture.width * i + j;
			if (ft_strncmp(dir, "NORTH", ft_strlen(dir)) == 0)
				game->texture.n_texture[pos] = mlx->img.add_itr[pos];
			else if (ft_strncmp(dir, "SOUTH", ft_strlen(dir)) == 0)
				game->texture.s_texture[pos] = mlx->img.add_itr[pos];
			else if (ft_strncmp(dir, "EAST", ft_strlen(dir)) == 0)
				game->texture.e_texture[pos] = mlx->img.add_itr[pos];
			else if (ft_strncmp(dir, "WEST", ft_strlen(dir)) == 0)
				game->texture.w_texture[pos] = mlx->img.add_itr[pos];
		}
	}
}



int	main(int argc, char **argv)
{
	t_game			game;
	t_display		mlx;
	char			*testmap[] = {
        "111111111111111",
        "100000000000101",
        "100001000000101",
        "111100000010101",
        "100000000030101",
        "100000001111101",
        "100000000000001",
        "100000000000001",
        "111311000111101",
        "100000000000001",
        "111111111111111"
    };
	t_texture		texture;

	(void)argc;
	(void)argv;
	game.map = testmap;
	game.map_height = 11;
	game.map_width = 15;
	game.floor_color = 0x6F8FAF;
	game.ceiling_color = 0x0000FF;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIN_WIDTH, \
				WIN_HEIGHT, "cub3D");
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.address = mlx_get_data_addr(mlx.img.img,
			&mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	game.display = mlx;
	texture.north = "../texture/brick_red.xpm";
	texture.south = "../texture/test.xpm";
	texture.east = "../texture/brick_gray.xpm";
	texture.west = "../texture/brick_graymoss.xpm";
	read_textures(&game, &mlx, texture.north, "NORTH");
	read_textures(&game, &mlx, texture.south, "SOUTH");
	read_textures(&game, &mlx, texture.east, "EAST");
	read_textures(&game, &mlx, texture.west, "WEST");
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, close_window_cross, &mlx);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(mlx.mlx);
	return (0);
}
