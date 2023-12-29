#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	parsing(argc, argv, &game);
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
	printf("Printfs dans la main pour check si toutes les textures sont correctes\n");
	printf("North  = %s\n", game.texture.north);
	printf("South  = %s\n", game.texture.south);
	printf("West  = %s\n", game.texture.west);
	printf("East  = %s\n", game.texture.east);
	printf("Floor = %d\n", game.texture.floor);
	printf("Ceiling = %d\n", game.texture.ceiling);
	return (0);
}
