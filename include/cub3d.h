#ifndef CUB3D_H
# define CUB3D_H

# include "../src/Libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "struct.h"
# include "enums.h"
# include "map2dtest.h"




# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GRAY 0xADADAD
# define GREEN 0x00FF00

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1300

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define X 0
# define Y 1

# define M_PI_3 4.71238898038  //3 *PI/2
# define FOV 1.0471975512 // M_PI /3
# define DEGINRAD 0.0174533
# define RAYCOUNT 30


/* Hooks */
int		keybindings(int keycode, t_gametest *game);
int		close_window_cross(t_display *display);
void	init_mlx(t_display *display, t_image_data *img);
void	my_mlx_pixel_put(t_image_data *img, t_point pixel);

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
