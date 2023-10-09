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

#endif
