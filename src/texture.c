/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/20 22:04:44 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture(t_game *game, char *texture, char *path)
{
	if (ft_strncmp(&path[ft_strlen(path) - 5], ".xpm", 3) != 0)
	{
		error_manager(game, "Texture path is not valid.");
	}
	if (texture == NULL)
		return (0);
	else
	{
		error_manager(game, "Texture path is not valid.");
	}
	return (1);
}

static int	check_color(t_game *game, int color)
{
	if (color == -1)
		return (0);
	else
	{
		error_manager(game, "Texture path is not valid.");
	}
	return (1);
}

static int	get_rgb(t_game *game, t_texture *texture, char c, char *path)
{
	char	**split;

	split = ft_split(path, ',');
	if (len_split(split) != 3)
		error_manager(game, "Wrong RGB");
	if (c == 'F')
	{
		if (texture->floor != -1)
			error_manager(game, "Wrong input");
		else
			texture->floor = rgb_to_hex(game, ft_atoi(split[0]),
					ft_atoi(split[1]), ft_atoi(split[2]));
	}
	else if (c == 'C')
	{
		if (texture->ceiling != -1)
			error_manager(game, "Wrong input");
		else
			texture->ceiling = rgb_to_hex(game, ft_atoi(split[0]),
					ft_atoi(split[1]), ft_atoi(split[2]));
	}
	ft_freesplit(split);
	return (0);
}

static void	assign_texture(t_game *game, t_texture *texture,
		char *direction, char *path)
{
	if (ft_strncmp(direction, "NO", ft_strlen(direction)) == 0)
		if (!(check_texture(game, texture->north, path)))
			texture->north = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "SO", ft_strlen(direction)) == 0)
		if (!(check_texture(game, texture->south, path)))
			texture->south = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "WE", ft_strlen(direction)) == 0)
		if (!(check_texture(game, texture->west, path)))
			texture->west = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "EA", ft_strlen(direction)) == 0)
		if (!(check_texture(game, texture->east, path)))
			texture->east = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "F", ft_strlen(direction)) == 0)
	{
		if (!(check_color(game, texture->floor)))
			get_rgb(game, texture, 'F', path);
	}
	if (ft_strncmp(direction, "C", ft_strlen(direction)) == 0)
		if (!(check_color(game, texture->ceiling)))
			get_rgb(game, texture, 'C', path);
}

void	get_texture(t_game *game, t_texture *texture, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return ;
	if (len_split(split) != 2)
	{
		error_manager(game, "Texture path is not valid.");
	}
	assign_texture(game, texture, split[0], split[1]);
	ft_freesplit(split);
}
