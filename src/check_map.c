#include "../include/cub3d.h"

/*
int	valid_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int check_borders_horizontal(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[0][col])
	{
		if (valid_char(map[0][col]))
			return (1); // if 0 or N on 1st row 
		col++;
	}
	while (map[row])
		row++;
	col = 0;
	while (map[row - 1][col])
	{
		if (valid_char(map[row - 1][col]))
			return (1); // if 0 or N on 1st row 
		col++;
	}
	return (0);
}

int check_borders_vertical(char **map)
{
}


int	check_around(char **map, int row, int col)
{
	// return 1 if error
	if (map[row - 1][col] != 1)
}

int	check_open_map(char **map)
{
	int	row;
	int	col;
	
	row = 0;
	if (check_borders_horizontal(**map)) // put a return
	
	return (0);
}
*/
