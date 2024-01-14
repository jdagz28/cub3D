#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			rgb;
	int			floor;
	int			ceiling;
	int			width;
	int 		height;
	int			n_texture[4096];
	int			s_texture[4096];
	int			w_texture[4096];
	int 		e_texture[4096];
}				t_texture;

typedef struct valid_text
{
	int	north;
	int	south;
	int	west;
	int	east;
}				valid_text;

typedef struct s_image_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*add_itr;
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
	int		color;
}	t_point;

typedef struct s_vector
{
	float	dir[2];
}	t_vector;

typedef struct s_ray
{
	float	angle;
	float	x;
	float	y;
	float	step_x;
	float	step_y;
	float	dof;
	int		map_intersect_x;
	int		map_intersect_y;
	float	length;
	float	dist_h;
	float	dist_v;
	float	h_x;
	float	h_y;
	float	v_x;
	float	v_y;
	float	dist;
	float	height;
	float	start;
	float	end;
	int		color;
	float	shade;
	int		hit;
}	t_ray;

typedef struct s_walltexture
{
	float	x;
	float	y;
	float	y_step;
	float	y_offset;
}	t_walltexture;

typedef struct s_player
{
	t_point		position;
	t_point		mat_position;
	t_vector	front;
	int			array_x;
	int			array_y;
	float		angle;
	t_vector	cam;
	char		direction;
}	t_player;

typedef struct s_game
{
	t_display	display;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	int			floor_color;
	int			ceiling_color;
	int			map_width;
	int			map_height;
	char		**map;
	char		**copy_map;
	int			fd;
}	t_game;

#endif
