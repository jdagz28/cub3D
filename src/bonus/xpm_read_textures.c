/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_read_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:32:51 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/14 21:32:59 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	read_textures(t_game *game, t_display *mlx, char *texture_path, \
							char *dir)
{
	int	i;
	int	j;
	int	pos;

	mlx->img.img = mlx_xpm_file_to_image(mlx->mlx, texture_path, \
						&game->texture.width, &game->texture.height);
	mlx->img.add_itr = (int *)mlx_get_data_addr(mlx->img.img, \
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
		{
			pos = game->texture.width * i + j;
			if (ft_strncmp(dir, "NORTH", ft_strlen(dir)) == 0)
				game->texture.n_texture[pos] = mlx->img.add_itr[pos];
			else if (ft_strncmp(dir, "SOUTH", ft_strlen(dir)) == 0)
				game->texture.s_texture[pos] = mlx->img.add_itr[pos];
			else if (ft_strncmp(dir, "EAST", ft_strlen(dir)) == 0)
				game->texture.e_texture[pos] = mlx->img.add_itr[pos];
			else if (ft_strncmp(dir, "WEST", ft_strlen(dir)) == 0)
				game->texture.w_texture[pos] = mlx->img.add_itr[pos];
		}
	}
}