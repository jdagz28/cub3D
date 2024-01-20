/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:51:52 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/20 12:59:06 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_all_textures(t_texture *texture)
{
	if (texture->north == NULL)
		return (0);
	if (texture->south == NULL)
		return (0);
	if (texture->west == NULL)
		return (0);
	if (texture->east == NULL)
		return (0);
	if (texture->floor == -1)
		return (0);
	if (texture->ceiling == -1)
		return (0);
	return (1);
}

int	check_char(char c)
{
	if (c == '0' || c == '1')
		return (1);
	else if (c == ' ')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (3);
	else
		return (0);
}

static void	fill_array(t_player *player, int x, int y, char z)
{
	player->array_x = x;
	player->array_y = y;
	player->direction = z;
}

void	check_char_map(t_game *game, char **map, t_player *player)
{
	int	coord[3];

	coord[0] = 0;
	coord[2] = 0;
	while (map[coord[0]])
	{
		coord[1] = 0;
		while (map[coord[0]][coord[1]])
		{
			if (check_char(map[coord[0]][coord[1]]) == 0)
				error_manager(game, "Wrong char in map.");
			else if (check_char(map[coord[0]][coord[1]]) == 2)
				map[coord[0]][coord[1]] = '2';
			else if (check_char(map[coord[0]][coord[1]]) == 3)
			{
				fill_array(player, coord[1], coord[0], map[coord[0]][coord[1]]);
				map[coord[0]][coord[1]] = '0';
				coord[2] += 1;
			}
			coord[1]++;
		}
		coord[0]++;
	}
	if (coord[2] != 1)
		error_manager(game, "More than one spawn.");
}

void	replace_threes(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
				map[i][j] = '0';
			j++;
		}
		printf("\n");
		i++;
	}
}
