#include "../include/cub3d.h"

static void	init_textures(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->rgb = -1;
	texture->floor = -1;
	texture->ceiling = -1;
}

t_game	*init_game(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->map = NULL;
	game->fd = 0;
	init_textures(&game->texture);
	return (game);
}
