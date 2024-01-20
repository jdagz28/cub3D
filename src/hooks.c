/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:51:52 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/20 12:59:37 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window_cross(t_game *game)
{
	free_all(game);
	mlx_destroy_image(game->display.mlx, game->display.img.img);
	mlx_destroy_window(game->display.mlx, game->display.window);
	exit(0);
}

int	keybindings(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		close_window_cross(game);
	else if (keycode == K_W || keycode == K_S)
		player_movement_y(keycode, game);
	else if (keycode == K_A || keycode == K_D)
		player_movement_x(keycode, game);
	else if (keycode == K_RIGHT)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle = 2 * M_PI;
		update_player_front(&game->player);
	}
	else if (keycode == K_LEFT)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * M_PI)
			game->player.angle = 0;
		update_player_front(&game->player);
	}
	return (0);
}
