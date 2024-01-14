/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:24:11 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/08 23:47:00 by jdagoy           ###   ########.fr       */
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
	game->player.position = create_point((WIN_WIDTH / 2), \
											WIN_HEIGHT / 2);
	game->player.array_x = game->map_width / 2;
	game->player.array_y = game->map_height / 2; 
	game->player.angle = M_PI;
	update_player_front(&game->player);
}
