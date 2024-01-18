#include "../include/cub3d.h"

int	len_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

void	ft_freesplit(char **tab)
{
	int	i;
	int	len;

	if (!tab)
		return ;
	i = -1;
	len = len_split(tab);
	if (++i < len)
		if (tab[i])
			free(tab[i]);
	free(tab);
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

float	deg_to_rad(float degrees)
{
	return (degrees * (M_PI / 180));
}

char	*skip_empty_line(int fd, char *line)
{
	while (line && line[0] == '\n')
		line = get_next_line(fd);
	return (line);
}

void replace_threes(char **map)
{
	int i, j;
	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
				map[i][j] = '0';
			j++;
		}
		printf("\n");
		i++;
	}
}
