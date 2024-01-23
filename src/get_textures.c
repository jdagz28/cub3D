/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:18:45 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/23 19:22:45 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	assign_xpm(t_texture *texture, t_image_data *img, \
							char *dir, int pos)
{
	if (pos >= 0 && pos <= texture->width * texture->height)
	{
		if (ft_strncmp(dir, "NORTH", ft_strlen(dir)) == 0)
			texture->n_texture[pos] = img->add_itr[pos];
		else if (ft_strncmp(dir, "SOUTH", ft_strlen(dir)) == 0)
			texture->s_texture[pos] = img->add_itr[pos];
		else if (ft_strncmp(dir, "EAST", ft_strlen(dir)) == 0)
			texture->e_texture[pos] = img->add_itr[pos];
		else if (ft_strncmp(dir, "WEST", ft_strlen(dir)) == 0)
			texture->w_texture[pos] = img->add_itr[pos];
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	read_textures(t_game *game, char *texture_path, char *dir)
{
	int				i;
	int				j;
	int				pos;
	t_image_data	img;

	img.img = mlx_xpm_file_to_image(game->display.mlx, texture_path, \
						&game->texture.width, &game->texture.height);
	if (img.img == NULL)
		error_manager(game, "Loading of .xpm image");
	img.add_itr = (int *)mlx_get_data_addr(img.img, \
			&img.bits_per_pixel, &img.line_length, &img.endian);
	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
		{
			pos = game->texture.width * i + j;
			if (assign_xpm(&game->texture, &img, dir, pos) != 0)
				error_manager(game, "Loading of .xpm image");
		}
	}
	mlx_destroy_image(game->display.mlx, img.img);
}

void	get_textures(t_game *game)
{
	read_textures(game, game->texture.north, "NORTH");
	read_textures(game, game->texture.south, "SOUTH");
	read_textures(game, game->texture.east, "EAST");
	read_textures(game, game->texture.west, "WEST");
}

int	count_commas(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
		if (string[i++] == ',')
			count++;
	if (count == 2)
		return (1);
	return (0);
}

int	checkspace(char *line)
{
	int	i;
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(line);
	i = -1;
	while (line[++i])
		if (line[i] == ' ')
			count++;
	if (count == len)
		return (1);
	return (0);
}
