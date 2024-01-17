/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:24:11 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/17 10:53:35 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	update_player_front(t_player *player)
{
	player->front.dir[X] = cos(player->angle) * 20;
	player->front.dir[Y] = (sin(player->angle) * 20) * -1;
}

void	init_player(t_game *game)
{
	game->player.array_x += 1;
	game->player.array_y += 1;
	game->player.position = create_point(game->player.array_x * TILE_SIZE, \
											game->player.array_y * TILE_SIZE);
	if (game->player.direction == 'N')
		game->player.angle = M_PI_2;
	else if (game->player.direction == 'S')
		game->player.angle = M_PI_3;
	else if (game->player.direction == 'W')
		game->player.angle = M_PI;
	else if (game->player.direction == 'E')
		game->player.angle = 2 * M_PI;
	update_player_front(&game->player);
}
