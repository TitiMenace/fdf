/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:39:35 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 06:01:59 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fdf.h"
#include "includes.h"

void	draw_line_pixel_put(t_data *data, t_point *seg, t_bresen *help)
{
	if (seg->col_b != 0 && data->end_color == 0)
		my_mlx_pixel_put(data, seg->a_x, seg->a_y, seg->col_b);
	else if (seg->col_a != 0 && data->end_color == 0)
		my_mlx_pixel_put(data, seg->a_x, seg->a_y, seg->col_a);
	else
		my_mlx_pixel_put(data, seg->a_x, seg->a_y, \
				get_interpolated_color(data, help->color1, \
					help->color2, help->scale));
}

void	last_pixel(t_data *data, t_point *seg, t_bresen *help)
{
	if ((seg->a_x == seg->b_x && seg->a_y == seg->b_y)
		&& (seg->a_x >= 0 && seg->a_x <= data->mlx.w_w)
		&& (seg->a_y >= 0 && seg->a_y <= data->mlx.w_h
			&& !(data->isometric == false && (seg->a_z + data->fov
					<= 0 && seg->b_z + data->fov <= 0))))
	{
		help->t += help->dt;
		help->scale = ((seg->z1_origin + help->t * (seg->z2_origin
						- seg->z1_origin)) - data->z_min)
			/ (data->z_max - data->z_min);
		my_mlx_pixel_put(data, seg->a_x, seg->a_y, \
				get_interpolated_color(data, help->color1, \
					help->color2, help->scale));
	}
}

void	bresenham(t_data *data, t_point *seg, t_bresen *help, t_line *utils)
{
	while ((seg->a_x != seg->b_x || seg->a_y != seg->b_y))
	{
		help->t += help->dt;
		help->scale = ((seg->z1_origin + help->t * (seg->z2_origin
						- seg->z1_origin)) - data->z_min)
			/ (data->z_max - data->z_min);
		if (!(seg->a_x >= data->mlx.w_w || seg->a_y >= data->mlx.w_h || seg->a_x < 0 || seg->a_y < 0) &&
				(data->isometric == true || (seg->a_z + data->fov > 0 && seg->b_z + data->fov > 0)))
			draw_line_pixel_put(data, seg, help);
		else
		{
			if (data->fast_mode)
				return ;
		}
		utils->err2 = utils->err;
		if (utils->err2 > -utils->dx)
		{
			utils->err -= utils->dy;
			seg->a_x += utils->sx;
		}
		if (utils->err2 < utils->dy)
		{
			utils->err += utils->dx;
			seg->a_y += utils->sy;
		}
		if (!(seg->a_x >= data->mlx.w_w || seg->a_y >= data->mlx.w_h || seg->a_x < 0 || seg->a_y < 0))
			last_pixel(data, seg, help);
	}
}

void	init_bresen_color(t_bresen *help, t_point *seg, t_data *data)
{
	if (seg->col_a != 0 && data->end_color == 0)
		help->color1 = seg->col_a;
	else
		help->color1 = data->start_color;
	if (seg->col_b != 0 && data->end_color == 0)
		help->color2 = seg->col_b;
	else
		help->color2 = data->end_color;
}
