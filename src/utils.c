/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/20 13:01:59 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	len_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	rgb_to_hex(t_game *game, int red, int green, int blue)
{
	int	res;

	res = -2;
	if (red < 0 || red > 255)
		error_manager(game, "Not RGB.");
	else if (green < 0 || green > 255)
		error_manager(game, "Not RGB.");
	else if (blue < 0 || blue > 255)
		error_manager(game, "Not RGB.");
	else
		res = (red << 16) | (green << 8) | blue;
	return (res);
}

float	deg_to_rad(float degrees)
{
	return (degrees * (M_PI / 180));
}

char	*skip_empty_line(int fd, char *line)
{
	while (line && line[0] == '\n')
		line = next_line(fd, line);
	return (line);
}

char	*next_line(int fd, char *line)
{
	free(line);
	return (get_next_line(fd));
}
