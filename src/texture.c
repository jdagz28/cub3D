#include "../include/cub3d.h"

static int	check_texture(char *texture, char *path)
{
	//int	fd;

	if (ft_strncmp(&path[ft_strlen(path) - 5], ".xpm", 3) != 0)
	{
		printf("Error: Textures not valid.\n");
		printf("Test ---------> %s\n", path); // test (delete)
		return (0);
	}
	if (texture == NULL)
		return (0);
	/*
	{
		if ((fd = open(path, O_RDONLY)) == -1)
		{
			printf("Error: Can't open file texture.\n");
			exit(1); // free + exit (delete)
		}
	}
	*/
	else
	{
		printf("Error: Textures not valid.\n");
		return (0);
	}
	return (1);
}

static int	check_color(int color)
{
	if (color == -1)
		return (0);
	else
	{
		printf("Error: Textures not valid.\n");
		return (0);
	}
	return (1);
}

static int	get_rgb(t_texture *texture, char c, char *path)
{
	char	**split;

	split = ft_split(path, ',');
	if (split[3] || !split[0] || !split[1] || !split[2])
	{
		ft_freesplit(split);
		return (1);
	}		
	if (c == 'F')
	{
		if (texture->floor != -1)
		{
			ft_freesplit(split);
			return (1);
		}
		else
			texture->floor = rgb_to_hex(ft_atoi(split[0]), 
					ft_atoi(split[1]), ft_atoi(split[2]));
	}
	else if (c == 'C')
	{
		if (texture->ceiling != -1)
		{
			ft_freesplit(split);
			return (1);
		}
		else
			texture->ceiling = rgb_to_hex(ft_atoi(split[0]), 
					ft_atoi(split[1]), ft_atoi(split[2]));
	}
	ft_freesplit(split);
	return (0);
}

static void	assign_texture(t_texture *texture, char *direction, char *path)
{
	if (ft_strncmp(direction, "NO", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->north, path)))
			texture->north = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "SO", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->south, path)))
			texture->south = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "WE", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->west, path)))
			texture->west = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "EA", ft_strlen(direction)) == 0)
		if (!(check_texture(texture->east, path)))
			texture->east = ft_strtrim(path, "\n");
	if (ft_strncmp(direction, "F", ft_strlen(direction)) == 0)
	{
		if (!(check_color(texture->floor)))
			get_rgb(texture, 'F', path);
	}
	if (ft_strncmp(direction, "C", ft_strlen(direction)) == 0)
		if (!(check_color(texture->ceiling)))
			get_rgb(texture, 'C', path);
}

void	get_texture(t_texture *texture, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return ;
	if (len_split(split) != 2)
	{
		if (len_split(split) != 0)
		{
			ft_freesplit(split);
			free(line);
			error_manager(NULL, "Texture path is not valid. \n");
		}
	}
	assign_texture(texture, split[0], split[1]);
	ft_freesplit(split);
}
