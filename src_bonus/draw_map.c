/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:31 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/11 00:21:19 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	projections(t_point *line, t_data *data, t_rot *r1, t_rot *r2)
{
	line->a_x = (int)line->start_x + x_projection(data, r1->x, r1->z);
	line->a_y = (int)line->start_y + y_projection(data, r1->y, r1->z);
	line->b_x = (int)line->start_x + x_projection(data, r2->x, r2->z);
	line->b_y = (int)line->start_y + y_projection(data, r2->y, r2->z);
	line->z1_origin = r1->z_origin;
	line->z2_origin = r2->z_origin;
	line->a_z = r1->z;
	line->b_z = r2->z;
	line->col_a = r1->col;
	line->col_b = r2->col;
}

void	init_rot(t_rot *rotate, float x, float y, float z, int color)
{
	rotate->x = x;
	rotate->y = y;
	rotate->z = z;
	rotate->col = color;
}

void	init_origin(t_rot *r1, t_rot *r2)
{
	r1->x = r2->x;
	r1->y = r2->y;
	r1->z = r2->z;	
}

void	draw(t_rot *r1, t_rot *r2, t_data *data,  t_point *line)
{
	projections(line, data, r1, r2);
	draw_line(data, line);
}


bool	draw_adjacent(int i, t_map ***map, t_data *data)
{
	int		j;
	int	origin_color;
	
	j = 0;
	while (j < data->line_len[i])
	{
		origin_color = (*map)[i][j + 1].color.hex;
		data->draw_helper.origin.z_origin = (*map)[i][j].z;
		if (j + 1 != data->line_len[i])
			data->draw_helper.right.z_origin = (*map)[i][j + 1].z;
		if (i + 1 != data->len_y)
			data->draw_helper.down.z_origin = (*map)[i + 1][j].z;
		if	(j == 0)
		{
			init_rot(&data->draw_helper.origin, (float)j - ((float)data->line_len[i] / 2), (float)i - (float)data->len_y / 2, (*map)[i][j].z, (*map)[i][j].color.hex);
			init_rotations(&data->draw_helper.origin, data);
		}
		else
			init_origin(&data->draw_helper.origin, &data->draw_helper.right);
		drawing(data, map, i, j);
		j++;
	}
	return(true);
}

bool	draw_map(t_map ***map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_y)
	{
		draw_adjacent(i, map, data);
		i++;
	}
	return (true);
}
