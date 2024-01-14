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

static void	init_player_parsing(t_player *player)
{
	player->position.axis[0] = 0;
	player->position.axis[1] = 0;
	player->mat_position.axis[0] = 0;
	player->mat_position.axis[1] = 0;
}

t_game	*init_game(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->map = NULL;
	game->fd = 0;
	init_textures(&game->texture);
	init_player_parsing(&game->player);
	return (game);
}
