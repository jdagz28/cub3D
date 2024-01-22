/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/22 17:51:23 by gmarchal         ###   ########.fr       */
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

static int	check_color(t_game *game, int color) // put this function in check_utils (delete static)
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

	tmp = ft_itoa(atoi_color);
	if (ft_strncmp(ft_strtrim(color, "\n"), tmp, ft_strlen(color)) != 0)
	{
		printf("Color = %s\n", color);
		error_manager(game, "Not RGB.");
	}
}

int	check_rgb(t_game *game, char *red, char *green, char *blue)
{
	int	i;
	int	res;

	i = 0;
	check_atoi(game, red, ft_atoi(red));
	check_atoi(game, green, ft_atoi(green));
	check_atoi(game, blue, ft_atoi(blue));
	res = rgb_to_hex(game, ft_atoi(red), ft_atoi(green), ft_atoi(blue));
	return (res);
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
