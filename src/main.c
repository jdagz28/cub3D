/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/17 18:50:28 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			game;

	parsing(argc, argv, &game);
	calc_mapdimensions(&game);
	init_mlx(&game.display);
	get_textures(&game);
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, \
				close_window_cross, &game.display);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(game.display.mlx);
	return (0);
}

/*
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
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
	printf("Printfs dans la main pour check si toutes les textures sont correctes\n");
	printf("North  = %s\n", game.texture.north);
	printf("South  = %s\n", game.texture.south);
	printf("West  = %s\n", game.texture.west);
	printf("East  = %s\n", game.texture.east);
	printf("Floor = %d\n", game.texture.floor);
	printf("Ceiling = %d\n", game.texture.ceiling);
	printf("Map :\n");
	print_map(game.map);
	return (0);
}
*/
