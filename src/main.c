#include "../include/cub3d.h"

void print_map(char **map)
{
	int i, j;
	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

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
	printf("Spawn [%f, %f]\n", game.player.mat_position.axis[0], game.player.mat_position.axis[1]);
	printf("Map :\n");
	print_map(game.map);
	return (0);
}
