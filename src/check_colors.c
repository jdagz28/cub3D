/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/23 03:39:39 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color(t_game *game, int color)
{
	if (color == -1)
		return (0);
	else
	{
		error_manager(game, "Texture path is not valid.");
	}
	return (1);
}

void	check_atoi(t_game *game, char *color, int atoi_color)
{
	char	*tmp;
	char	*color_trim;

	tmp = ft_itoa(atoi_color);
	color_trim = ft_strtrim(color, "\n");
	if (ft_strncmp(color_trim, tmp, ft_strlen(color)) != 0)
	{
		printf("Color = %s\n", color);
		free(tmp);
		free(color_trim);
		error_manager(game, "Not RGB.");
	}
	free(tmp);
	free(color_trim);
}

int	check_rgb(t_game *game, char *red, char *green, char *blue)
{
	int	res;

	check_atoi(game, red, ft_atoi(red));
	check_atoi(game, green, ft_atoi(green));
	check_atoi(game, blue, ft_atoi(blue));
	res = rgb_to_hex(game, ft_atoi(red), ft_atoi(green), ft_atoi(blue));
	return (res);
}
