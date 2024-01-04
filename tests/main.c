/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/04 03:07:56 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_game *game)
{
	for (int i = 0; i < game->map_height; i++)
	{
		for (int j = 0; j < game->map_width; j++)
			printf("%c ", game->map[i][j]);
		printf("\n");
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
        "100000000010101",
        "100000001111101",
        "100000000000001",
        "100000000000001",
        "111111000111101",
        "100000000000001",
        "111111111111111"
    };

	(void)argc;
	(void)argv;
	// init_testmap(&game);
	// parsing(argc, argv, &game);
	game.map = testmap;
	game.map_height = 11;
	game.map_width = 15;
	// print_map(&game);
	mlx.mlx = mlx_init();
	game.window_width = game.map_width * TILE_SIZE * 2;
	game.window_height = game.map_height * TILE_SIZE;
	// printf("%d %d\n", game.window_height, game.window_width);
	// fflush(stdout);
	mlx.window = mlx_new_window(mlx.mlx, game.window_width, \
				game.window_height, "cub3D");
	mlx.img.img = mlx_new_image(mlx.mlx, game.window_width, game.window_height);
	mlx.img.address = mlx_get_data_addr(mlx.img.img,
			&mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	game.display = mlx;
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, close_window_cross, &mlx);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(mlx.mlx);
	return (0);
}
