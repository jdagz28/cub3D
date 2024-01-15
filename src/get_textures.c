/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:18:45 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 10:19:50 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	read_textures(t_game *game, t_display *mlx, char *texture_path, \
							char *dir)
{
	int	i;
	int	j;
	int	pos;

	mlx->img.img = mlx_xpm_file_to_image(game->display.mlx, texture_path, \
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
			if (pos > 4095)
				break ;
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
