/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:55:06 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/19 10:06:25 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	exit_copymap(char **temp, int i)
{
	while (--i >= 0)
		free(temp[i]);
	free(temp);
	return (EXIT_FAILURE);
}

int	process_map(t_game *game, char **map)
{
	char	**temp;
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
			return (exit_copymap(temp, i));
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
