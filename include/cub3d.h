#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "struct.h"
# include "enums.h"
# include "map2dtest.h"

# define PI 3.1415

# define WHITE 0xFFFFFF
# define RED 0xFF0000

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1300

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define X_AXIS 0
# define Y_AXIS 1

/* Hooks */
int		keybindings(int keycode, t_gametest *game);
int		close_window_cross(t_display *display);
void	init_mlx(t_display *display, t_image_data *img);
void	my_mlx_pixel_put(t_image_data *img, t_point pixel);

#endif
