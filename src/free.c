/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:11:19 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/18 15:19:52 by jdagoy           ###   ########.fr       */
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
	if (game->map)
	{
		ft_freesplit(game->map);
		game->map = NULL;
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