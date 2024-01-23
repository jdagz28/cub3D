/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/23 19:23:23 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture(t_game *game, char *texture, char *path)
{
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".xpm", 3) != 0)
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

static int	get_rgb(t_game *game, t_texture *texture, char c, char *path)
{
	char	**split;

	split = ft_split(path, ',');
	if (len_split(split) != 3)
		error_manager(game, "Not RGB");
	if (c == 'F')
	{
		if (texture->floor != -1)
			error_manager(game, "Wrong input");
		else
			texture->floor = check_rgb(game, split[0], split[1], split[2]);
	}
	else if (c == 'C')
	{
		if (texture->ceiling != -1)
			error_manager(game, "Wrong input");
		else
			texture->ceiling = check_rgb(game, split[0], split[1], split[2]);
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

int	get_texture(t_game *game, t_texture *texture, char *line)
{
	char	**split;
	char	f_or_c;

	if (checkspace(line) == 1)
		return (0);
	f_or_c = 0;
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		f_or_c = 1;
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	if (len_split(split) != 2)
	{
		if (f_or_c == 1)
			error_manager(game, "Wrong RGB. Example : F 0,255,255");
		else
			error_manager(game, "Texture path is not valid.");
	}
	if (f_or_c == 1 && count_commas(split[1]) == 0)
		error_manager(game, "Wrong RGB.");
	assign_texture(game, texture, split[0], split[1]);
	ft_freesplit(split);
	return (0);
}
