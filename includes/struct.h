/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:06:31 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/14 03:04:21 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_map
{
	int len_x;
	int len_y;
	int	**plan;
}				t_map;

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

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_color	couleur;
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

#endif
