/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:06:31 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/10 01:48:13 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	 int		z;
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
		int	start_x;
		int	start_y;
		
}				t_point;

typedef	struct	s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int err;
	int err2;
}				t_line;

typedef struct	s_data
{
	t_mlx	mlx;
	t_point	point;
	int		*line_len;
	int		len_y;
}				t_data;

#endif
