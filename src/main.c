/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 10:53:15 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			game;
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

	(void)argc;
	(void)argv;
	game.map = testmap;
	game.map_height = 11;
	game.map_width = 15;
	game.floor_color = 0x6F8FAF;
	game.ceiling_color = 0x0000FF;
	init_mlx(&game.display);
	get_textures(&game);
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, close_window_cross, &game.display);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(game.display.mlx);
	return (0);
}
