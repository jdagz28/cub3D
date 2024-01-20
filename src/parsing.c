/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/20 13:01:13 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	arg_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		printf("Error\nMap is not .cub\n");
		exit(EXIT_FAILURE);
	}
}

char	**get_map(int fd, char *start)
{
	char	*line;
	char	**array;
	char	*temp;

	start = skip_empty_line(fd, start);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(start, line);
		free(start);
		if (!temp)
			return (NULL);
		start = temp;
		line = next_line(fd, line);
	}
	free(line);
	array = ft_split(start, '\n');
	free(start);
	return (array);
}

void	map_functions(t_game *game, char *line)
{
	game->map = get_map(game->fd, line);
	if (game->map == NULL)
		error_manager(game, "Map parsing error");
	check_char_map(game, game->map, &game->player);
	check_wall_map(game->map, game->player.array_x,
		game->player.array_y);
	replace_threes(game->map);
}

static void	get_data(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line && !check_all_textures(&game->texture))
	{
		while (line && line[0] == '\n')
			line = next_line(game->fd, line);
		get_texture(game, &game->texture, line);
		if (line && line[0] != '\0')
			line = next_line(game->fd, line);
		else
			break ;
	}
	if (!check_all_textures(&game->texture))
	{
		free(line);
		error_manager(game, "Missing textures.");
	}
	map_functions(game, line);
}

int	parsing(int argc, char **argv, t_game *game)
{
	arg_error(argc, argv);
	init_game(game);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		printf("Error\nCan't open file.\n");
		exit(1);
	}
	get_data(game);
	close(game->fd);
	return (0);
}
