/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:24:11 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/04 02:31:33 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	update_player_front(t_player *player)
{
	player->front.dir[X] = cos(player->angle) * 5;
	player->front.dir[Y] = (sin(player->angle) * 5) * -1;
}

void	init_player(t_game *game)
{
	game->player.position = create_point((game->window_width / 2) / 2, \
											game->window_height / 2);
	game->player.angle = M_PI / 2;
	update_player_front(&game->player);
}
