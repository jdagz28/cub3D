#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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


# define TILE_SIZE 64

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GRAY 0xADADAD
# define GREEN 0x00FF00

# define WIN_WIDTH 1280
# define WIN_HEIGHT 900

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define X 0
# define Y 1

# define M_PI_3 4.71238898038  //3 *PI/2
# define FOV 1.0471975512 // M_PI /3
# define DEGINRAD 0.0174533
# define MOVE_SPEED 1.5

/* Hooks */
int			keybindings(int keycode, t_game *game);
int			close_window_cross(t_display *display);

/* Parsing */
int			parsing(int argc, char **argv, t_game *game);

/* Init */
t_game		*init_game(t_game *game);

/* Texture */
void		get_texture(t_texture *texture, char *line);

/* Check Map */
int check_borders_horizontal(char **map);
void check_wall_map(char **map, int y, int x);

/* Utils */
int			len_split(char **split);
int			rgb_to_hex(int red, int green, int blue);
float		deg_to_rad(float degrees);
char		*skip_empty_line(int fd, char *line);

// mlx
void		init_mlx(t_display *display, t_image_data *img);
void		my_mlx_pixel_put(t_image_data *img, t_point pixel);

// create_vectorpoint.c
t_point		create_point(float x, float y);
t_vector	create_vector(float x, float y);

// draw_3d.c
void		draw_3d(t_game *game, int raynum);

// draw_line.c
void		draw_direction_dda(t_image_data *img, t_point start, \
								t_vector front);
void		draw_line_dda(t_image_data *img, t_point start, t_point end);

// draw_map.c
int		draw_map(t_game *game);

// draw_maptiles_bonus.c
void		draw_grids(t_display *mlx);
void		draw_maptiles(t_game *game, t_display *mlx);

// draw_minimap_bonus.c
void		draw_minimap(t_game *game);

// init_player.c
void		update_player_front(t_player *player);
void		init_player(t_game *game);

// set_color.c
void		set_color(char *buffer, int endian, int color, int alpha);

// raycaster_angles.c
void		set_horizontal_angle(t_game *game, float arc_tan);
void		set_vertical_angle(t_game *game, float tangent);

// raycaster_castrays.c
void		cast_horizontal_rays(t_game *game);
void		cast_vertical_rays(t_game *game);

// raycaster.c
float		get_distance(float x1, float y1, float x2, float y2);
void		draw_ray(t_game *game);


//movement_y.c
int			check_playerpos(t_game *game);
int			offset_check(t_game *game, char *type, int value);
void		player_movement_y(int keycode, t_game *game);

//movement_x.c
void		player_movement_x(int keycode, t_game *game);

//xpm_read_textures.c
void	read_textures(t_game *game, t_display *mlx, char *texture_path, \
							char *dir);

#endif
