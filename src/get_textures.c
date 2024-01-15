/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:18:45 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 02:58:37 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures(t_game *game)
{
	game->texture.north = "../texture/brick_red.xpm";
	game->texture.south = "../texture/test.xpm";
	game->texture.east = "../texture/brick_gray.xpm";
	game->texture.west = "../texture/brick_graymoss.xpm";
	read_textures(game, &game->display, game->texture.north, "NORTH");
	read_textures(game, &game->display, game->texture.south, "SOUTH");
	read_textures(game, &game->display, game->texture.east, "EAST");
	read_textures(game, &game->display, game->texture.west, "WEST");
}
