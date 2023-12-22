#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	int			rgb;
	int			floor;
	int			ceiling;
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
}	t_image_data;

typedef struct s_display
{
	void			*mlx;
	void			*window;
	t_image_data	img;
}			t_display;

typedef struct s_player
{
	float	x;
	float	y;
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
