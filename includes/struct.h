/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:06:31 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/27 00:13:45 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


# include <stdbool.h>

typedef unsigned char	t_v3uc __attribute__((vector_size (16)));

typedef union	s_color
{
	int	hex;
	struct
	{
		char	b;
		char	g;
		char	r;
		char	a;
	};
}				t_color;

typedef struct	s_map
{
	 float		z;
	 t_color	color;

}				t_map;


typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		w_w;
	int		w_h;
}				t_mlx;


typedef struct	s_point
{
		int		a_x;
		int		a_y;
		int		b_x;
		int		b_y;
		int		start_x;
		int		start_y;
		int		z1_origin;
		int		z2_origin;
		int		a_z;
		int		b_z;
		int		col_a;
		int		col_b;

}				t_point;

typedef struct s_rot
{
	float	x;
	float	y;
	float	z;
	float	z_origin;
	int		col;
}				t_rot;


typedef	struct	s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int err;
	int err2;
}				t_line;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct	s_angle
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
}				t_angle;

typedef struct	s_data
				t_data;
typedef struct	s_data
{
	t_angle angle;
	t_map	**map;
	t_mlx	mlx;
	t_point	line;
	t_img	img;
	int		*line_len;
	int		len_y;
	float	offset;
	unsigned int	start_color;
	unsigned int	end_color;
	float	z_max;
	float	z_min;
	int fov;
	bool	special_rendering;
	bool	isometric;
	float	cinematic;
	unsigned char	alpha;
	bool	set_alpha_mode;
	bool	set_cinematic;
	float	cinematic_x;
	float	cinematic_y;
	float	cinematic_z;
	int	(*get_color)(t_data *data, float z_origin, float z_rotated);
}				t_data;

#endif
