/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:25:29 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/14 01:32:17 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_playerpos(t_game *game)
{
	game->player.array_x = (int)game->player.position.axis[X] / TILE_SIZE;
	game->player.array_y = (int)game->player.position.axis[Y] / TILE_SIZE;
	if (game->player.array_x < 0 || game->player.array_y < 0)
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
			game->player.position.axis[X] += game->player.front.dir[X];
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] += game->player.front.dir[Y];
	}
	if (keycode == K_S)
	{
		if (game->map[game->player.array_y][x] == '0')
			game->player.position.axis[X] -= game->player.front.dir[X];
		if (game->map[y][game->player.array_x] == '0')
			game->player.position.axis[Y] -= game->player.front.dir[Y];
	}
}

int	check_ymovement_add_x(t_game *game, int offset)
{
	int	res;

	res = (game->player.position.axis[X] + \
				offset) / TILE_SIZE;
	return (res);
}

int	check_ymovement_add_y(t_game *game, int offset)
{
	int	res;

	res = (game->player.position.axis[Y] + \
				offset) / TILE_SIZE;
	return (res);
}

int	check_ymovement_sub_x(t_game *game, int offset)
{
	int	res;

	res = (game->player.position.axis[X] - \
				offset) / TILE_SIZE;
	return (res);
}

int	check_ymovement_sub_y(t_game *game, int offset)
{
	int	res;

	res = (game->player.position.axis[Y] - \
				offset) / TILE_SIZE;
	return (res);
}

void	player_movement_y(int keycode, t_game *game)
{
	int	x_offset;
	int	y_offset;
	int	add_x;
	int	add_y;
	int	sub_x;
	int	sub_y;

	if (check_playerpos(game) == 0)
		return ;
	if (game->player.front.dir[X] < 0)
		x_offset = -20;
	else
		x_offset = 20;
	if (game->player.front.dir[Y] < 0)
		y_offset = -20;
	else
		y_offset = 20;
	add_x = check_ymovement_add_x(game, x_offset);
	add_y = check_ymovement_add_y(game, y_offset);
	sub_x = check_ymovement_sub_x(game, x_offset);
	sub_y = check_ymovement_sub_y(game, y_offset);
	if (keycode == K_W)
		move_y(game, add_x, add_y, keycode);
	if (keycode == K_S)
		move_y(game, sub_x, sub_y, keycode);
}
