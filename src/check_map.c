#include "../include/cub3d.h"

int	valid_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	check_wall_map(char **map, int y, int x)
{
	int	height;

	height = get_height(map);
	if (x > (int)ft_strlen(map[x]) - 1 || map[x][y] == '2')
	{
		printf("Error: Map not closed.\n");
		exit(1); // free + error return (delete)
	}
	if (map[x][y] == '3' || map[x][y] == '1')
		return ;
	if (x == 0 || y == 0 || x == height - 1 || y == ft_strlen(map[x]) - 1)
	{
		printf("Error: Map not closed.\n");
		exit(1); // free + return (delete)
	}
	map[x][y] = '3';
	check_wall_map(map, y + 1, x);
	check_wall_map(map, y, x + 1);
	check_wall_map(map, y, x - 1);
	check_wall_map(map, y - 1, x);
}
