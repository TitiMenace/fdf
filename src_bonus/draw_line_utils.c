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
	my_mlx_pixel_put(data, seg->a_x, seg->a_y, \
				get_interpolated_color(data, help->color1, \
					help->color2, help->t));
}

void	bresenham(t_data *data, t_point *seg, t_bresen *help, t_line *utils)
{
	while ((seg->a_x != seg->b_x || seg->a_y != seg->b_y)
			&& (seg->a_x >= 0 && seg->a_x <= 1920) && (seg->a_y >= 0 && seg->a_y <= 1080))
	{
		help->t += help->dt;
		if ((data->isometric == true || (seg->a_z + data->fov > 0 && seg->b_z + data->fov > 0)))
			draw_line_pixel_put(data, seg, help);
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
	}
}

void	init_bresen_color(t_bresen *help, t_point *seg, t_data *data)
{
	double	a_scale;
	double	b_scale;

	if (data->z_max == data->z_min)
	{
		a_scale = 0;
		b_scale = 0;
	}
	else
	{
		a_scale = help->scale = (seg->z1_origin - data->z_min) / (data->z_max - data->z_min);
		b_scale = help->scale = (seg->z2_origin - data->z_min) / (data->z_max - data->z_min);
	}
	help->color1 = seg->col_a;
	help->color2 = seg->col_b;
	if (seg->col_a == 0 || data->end_color != 0)
		help->color1 = get_interpolated_color(data, data->start_color, data->end_color, a_scale);
	if (seg->col_b == 0 || data->end_color != 0)
		help->color2 = get_interpolated_color(data, data->start_color, data->end_color, b_scale);
}
