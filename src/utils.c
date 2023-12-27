#include "../include/cub3d.h"

int	len_split(char **split)
{
	int i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	rgb_to_hex(int red, int green, int blue)
{
	int	res;

	res = -2;
	if (red < 0 || red > 255)
		return (-1);
	else if (green < 0 || green > 255)
		return (-1);
	else if (blue < 0 || blue > 255)
		return (-1);
	else
		res = (red << 16) | (green << 8) | blue;
	return (res);
}
