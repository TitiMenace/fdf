/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:06:31 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/20 04:01:48 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


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
		float	a_x;
		float	a_y;
		float	b_x;
		float	b_y;
		float	start_x;
		float	start_y;
		float	z1_origin;
		float	z2_origin;
		float	a_z;
		float	b_z;

}				t_point;

typedef struct s_rot
{
	float	x;
	float	y;
	float	z;
	float	z_origin;
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
	//bool	isometric;
	int	(*get_color)(t_data *data, float z_origin, float z_rotated);

}				t_data;

#endif
