/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:55:11 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/11 00:28:15 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fdf.h"
#include "includes.h"

static int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

static void	init_s_line(t_line *utils)
{
	utils->dx = 0; 
	utils->dy = 0;
	utils->sx = 0;
	utils->sy = 0;
	utils->err = 0;
	utils->err2 = 0;

}

static int	def_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

static int	def_error(int a, int b)
{
	if (a > b)
		return (a / 2);
	else
		return (-b / 2);
}
void	draw_line(t_data *data, t_point *seg)
{
	t_line	utils;
	int	err2;
	double	scale;
	double	t;
	double	dt;
	int		color1;
	int		color2;

//	if (seg->col_a != 0)
		color1 = data->start_color;
//	else
//		color1 = seg->col_a;
//	if (seg->col_b != 0)
		color2 = data->end_color;
//	else
//		color2 = seg->col_b;
	init_s_line(&utils);
	utils.dx = ft_abs(seg->b_x - seg->a_x);
	utils.dy = ft_abs(seg->b_y - seg->a_y);
	utils.sx = def_slope(seg->a_x, seg->b_x);
	utils.sy = def_slope(seg->a_y, seg->b_y);
	utils.err = def_error(utils.dx, utils.dy);
	
	t = 0.0;
	dt = 1.0 / (sqrt(utils.dx * utils.dx + utils.dy * utils.dy));
	
	if ((seg->a_x >= 0 && seg->a_x <= data->mlx.w_w) && (seg->a_y >= 0 && seg->a_y <= data->mlx.w_h))
	{
		while ((seg->a_x != seg->b_x || seg->a_y != seg->b_y) && (seg->a_x >= 0 && seg->a_x <= data->mlx.w_w) && (seg->a_y >= 0 && seg->a_y <= data->mlx.w_h && !(data->isometric == false && (seg->a_z + data->fov <= 0 && seg->b_z + data->fov <= 0))))
		{
			t += dt;
			scale = ((seg->z1_origin + t * (seg->z2_origin - seg->z1_origin)) - data->z_min) / (data->z_max - data->z_min);
			my_mlx_pixel_put(data, seg->a_x, seg->a_y, get_interpolated_color(data, color1, color2, scale));
			err2 = utils.err;
			if (err2 > -utils.dx)
			{
				utils.err -= utils.dy;
				seg->a_x += utils.sx;
			}
			if (err2 < utils.dy)
			{
				utils.err += utils.dx;
				seg->a_y += utils.sy;
			}
			if ((seg->a_x == seg->b_x && seg->a_y == seg->b_y) && (seg->a_x >= 0 && seg->a_x <= data->mlx.w_w) && (seg->a_y >= 0 && seg->a_y <= data->mlx.w_h && !(data->isometric == false && (seg->a_z + data->fov <= 0 && seg->b_z + data->fov <= 0))))
			{
				t += dt;
				scale = ((seg->z1_origin + t * (seg->z2_origin - seg->z1_origin)) - data->z_min) / (data->z_max - data->z_min);
				my_mlx_pixel_put(data, seg->a_x, seg->a_y, get_interpolated_color(data, color1, color2, scale));
			}
		}
	}
}
