#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	void		*north;
	void		*south;
	void		*west;
	void		*east;
}				t_texture;

typedef struct s_image_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_data;

typedef struct s_display
{
	void			*mlx;
	void			*window;
	t_image_data	img;
}			t_display;

typedef struct s_point
{
	float	axis[2];
}	t_point;

typedef struct s_vector
{
	float	dir[2];
} t_vector;

typedef struct s_player
{
	t_point		position;
	t_point		mat_position;
	t_vector	front; //delta
	t_vector	cam;
	float		angle;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_texture	texture;
	//int floor_color;
	//int ceiling_color;
	int			map_width;
	int			map_height;
	char		**map;
	int			fd;
}	t_game;

#endif
