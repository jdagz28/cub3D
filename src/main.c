/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/21 16:52:24 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	main(int argc, char **argv)
{
	t_game			game;

	parsing(argc, argv, &game);
	calc_mapdimensions(&game);
	if (process_map(&game, game.map) != 0)
		error_manager(&game, "Calloc error");
	if (init_mlx(&game.display) != 0)
		error_manager(&game, "MLX initialization failed");
	get_textures(&game);
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, \
				close_window_cross, &game);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(game.display.mlx);
	return (EXIT_SUCCESS);
}
*/
void print_map(char **map)
{
	int i, j;
	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	parsing(argc, argv, &game);
	printf("Floor = %d\n", game.texture.floor);
	printf("Ceiling = %d\n", game.texture.ceiling);
	printf("Map :\n");
	print_map(game.map);
	return (0);
}
