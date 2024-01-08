/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:29 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/08 12:30:13 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_playerpos(t_game *game)
{
	game->player.array_x = (int)game->player.position.axis[X] / TILE_SIZE;
	game->player.array_y = (int)game->player.position.axis[Y] / TILE_SIZE;
	if (game->player.array_x < 0)
		return (0);
	if (game->player.array_y < 0)
		return (0);
	return (1);
}

int offset_check(t_game *game, char *type, int value)
{
	int res;

	res = 0;
	if (value < 0)
		res = 0;
	else if (ft_strncmp(type, "add_x", ft_strlen(type)) == 0 || \
				ft_strncmp(type, "sub_x", ft_strlen(type)) == 0)
		res = game->map_width;
	else if (ft_strncmp(type, "add_y", ft_strlen(type)) == 0 || \
				ft_strncmp(type, "sub_y", ft_strlen(type)) == 0)
		res = game->map_height;
	return res;
}

static void	move_y(t_game *game, int x, int y, int keycode)
{
	if (keycode == K_W)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] += game->player.front.dir[X] * MOVE_SPEED;
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.front.dir[Y] * MOVE_SPEED;
	}
	if (keycode == K_S)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[X] * MOVE_SPEED;
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[Y] * MOVE_SPEED;
	}
}

void	player_movement_y(int keycode, t_game *game)
{
	int	add_x;
	int	add_y;
	int	sub_x;
	int	sub_y;

	if (check_playerpos(game) == 0)
		return ;
	add_x = (game->player.position.axis[X] - game->player.front.dir[X]) / TILE_SIZE - 0.2;
	if (add_x < 0 || add_x > game->map_width)
		add_x = offset_check(game, "add_x", add_x);
	add_y = (game->player.position.axis[Y] - game->player.front.dir[Y]) / TILE_SIZE - 0.2;
	if (add_y < 0 || add_y > game->map_height)
		add_y = offset_check(game, "add_y", add_y);
	sub_x = (game->player.position.axis[X] + game->player.front.dir[X]) / TILE_SIZE + 0.2;
	if (sub_x < 0 || sub_x > game->map_width)
		sub_x = offset_check(game, "sub_x", sub_x);
	sub_y = (game->player.position.axis[Y] + game->player.front.dir[Y]) / TILE_SIZE + 0.2;
	if (sub_y < 0 || sub_y > game->map_height)
		sub_y = offset_check(game, "sub_y", sub_y);
	if (keycode == K_W)
		move_y(game, add_x, add_y, keycode);
	if (keycode == K_S)
		move_y(game, sub_x, sub_y, keycode);
}