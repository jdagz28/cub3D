/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/18 23:48:04 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	process_map(t_game *game, char **map)
{
	char 	**temp;
	int		i;
	int		j;
	
	temp = (char **)ft_calloc(sizeof(char *), game->map_height);
	if (temp == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < game->map_height)
	{
		temp[i] = (char *)ft_calloc(sizeof(char), game->map_width + 1);
		if (temp[i] == NULL)
		{	
			while (--i >= 0)
				free(temp[i]);
			free(temp);
			return (EXIT_FAILURE);
		}
		j = -1;
		while (++j < ft_strlen(map[i]))
			temp[i][j] = map[i][j];
		while (j < game->map_width)
			temp[i][j++] = ' ';
		temp[i][j] = '\0';
	}
	ft_freesplit(game->map);
	game->map = temp;
	return (EXIT_SUCCESS);
}

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

/*   DELETE BEFORE PUSHING FOR CORRECTION
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
