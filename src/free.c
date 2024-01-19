/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:11:19 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/19 09:50:56 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->east)
		free(texture->east);
	if (texture->west)
		free(texture->west);
}


void	free_all(t_game *game)
{
	int	i;

	if (game->map)
	{
		if (game->map_height != 0)
		{
			i = -1;
			while (++i < game->map_height)
				free(game->map[i]);
		}
		else
			ft_freesplit(game->map);
	}
	free_textures(&game->texture);
}

static void	print_error(char *error_msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}


int	error_manager(t_game *game, char *error_msg)
{
	free_all(game);
	print_error(error_msg);
	exit(EXIT_FAILURE);
}
