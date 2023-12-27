#ifndef CUB3D_H
# define CUB3D_H

# include "../src/Libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "struct.h"
# include "enums.h"

# define PI 3.1415

# define WHITE 0xFFFFFF
# define RED 0xFF0000

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1300

/* Hooks */
void	ft_mlx_hooks(t_display *display);

/* Parsing */
int	parsing(int argc, char **argv, t_game *game);

/* Init */
t_game *init_game(t_game *game);

/* Texture */
void	get_texture(t_texture *texture, char *line);

/* Utils */
int	len_split(char **split);
int	rgb_to_hex(int red, int green, int blue);

#endif
