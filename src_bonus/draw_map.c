/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:29:30 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/16 15:06:18 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	projections(t_point *line, t_data *data, t_rot *r1, t_rot *r2)
{
	line->a_x = line->start_x + x_projection(data, r1->x, r1->z);
	line->a_y = line->start_y + y_projection(data, r1->y, r1->z);
	line->b_x = line->start_x + x_projection(data, r2->x, r2->z);
	line->b_y = line->start_y + y_projection(data, r2->y, r2->z);
	line->z1_origin = r1->z_origin;
	line->z2_origin = r2->z_origin;
	line->a_z = r1->z;
	line->b_z = r2->z;
}

void	init_rot(t_rot *rotate, float x, float y, float z, t_point *line)
{
	(void)line;
	rotate->x = x;
	rotate->y = y;
	rotate->z = z;
}

void	init_origin(t_rot *r1, t_rot *r2)
{
	r1->x = r2->x;
	r1->y = r2->y;
	r1->z = r2->z;
}

void	draw(t_rot *r1, t_rot *r2, t_data *data,  t_point *line, int color)
{
	projections(line, data, r1, r2);
	draw_line(data, line, color);
}


bool	draw_adjacent(int i, t_map ***map, t_data *data, t_point *line)
{
	t_rot	origin;
	t_rot	right;
	t_rot	down;
	int		j;
	
	j = 0;
	while (j < data->line_len[i])
	{
		origin.z_origin = (*map)[i][j].z;
		if (j + 1 != data->line_len[i])
			right.z_origin = (*map)[i][j + 1].z;
		if (i + 1 != data->len_y)
			down.z_origin = (*map)[i + 1][j].z;
		if	(j == 0)
		{
			init_rot(&origin, (float)j - ((float)data->line_len[i] / 2), (float)i - (float)data->len_y / 2, (*map)[i][j].z, line);
			//init_rot(&origin, (float)j, (float)i, (*map)[i][j].z, line);
			init_rotations(&origin, data);
		}
		else
			init_origin(&origin, &right);
		if (j + 1 == data->line_len[i] && i + 1 != data->len_y)
		{
			init_rot(&down, (float)j - ((float)data->line_len[i] / 2), ((float)i - (float)data->len_y / 2) + 1, (*map)[i + 1][j].z, line);
			//init_rot(&down, (float)j, (float)i + 1, (*map)[i + 1][j].z, line);
			if (data->special_rendering == true)
				init_special_rotations(&down, data);
			else
				init_rotations(&down, data);
			draw(&origin, &down, data, line, 0x00ff0000);
		}
		else if (i + 1 == data->len_y)
		{
			if (j + 1 == data->line_len[i])
				break;
			init_rot(&right, ((float)j - (float)data->line_len[i] / 2) + 1, (float)i - (float)data->len_y / 2, (*map)[i][j + 1].z, line);
			//init_rot(&right, (float)j + 1, (float)i, (*map)[i][j + 1].z, line);
			init_special_rotations(&right, data);
			draw(&origin, &right, data, line, 0x00ff0000);
		}
		else
		{
			init_rot(&right, ((float)j - (float)data->line_len[i] / 2) + 1, (float)i - (float)data->len_y / 2, (*map)[i][j + 1].z, line);
			//init_rot(&right, (float)j + 1, (float)i, (*map)[i][j + 1].z, line);
			init_rot(&down, (float)j - ((float)data->line_len[i] / 2), ((float)i - (float)data->len_y / 2) + 1, (*map)[i + 1][j].z, line);
			//init_rot(&down, (float)j, (float)i + 1, (*map)[i + 1][j].z, line);
			init_rotations(&right, data);
			if (data->special_rendering == true)
				init_special_rotations(&down, data);
			else
				init_rotations(&down, data);
			draw(&origin, &right, data, line, 0x00ff0000);
			draw(&origin, &down, data, line, 0x00ff0000);
		}
		j++;
	}
	return (true);
}

void	final_draw(t_map ***map, t_data *data, t_point *line)
{
	t_rot	right;
	t_rot	origin;
	int		j;
	int		i;

	i = data->len_y - 1;
	j = 0;
	while (j + 1 < data->line_len[i])
	{
		if	(j == 0)
		{
			init_rot(&origin, (float)j - ((float)data->line_len[i] / 2), (float)i - (float)data->len_y / 2, (*map)[i][j].z, line);
			init_rotations(&origin, data);
		}
		init_rot(&right, ((float)j - (float)data->line_len[i] / 2) + 1, (float)i - (float)data->len_y / 2, (*map)[i][j + 1].z, line);
		init_rotations(&right, data);
		draw(&origin, &right, data, line, 0x00ff0000);
		init_origin(&origin, &right);
		j++;
	}
}


void	right_line(t_map ***map, t_data *data, t_point *line)
{
	t_rot	down;
	t_rot	origin;
	int		j;
	int		i;

	j = data->line_len[0] - 1;
	i = 0;
	while (i + 1 < data->len_y)
	{
		if	(i == 0)
		{
			init_rot(&origin, (float)j - ((float)data->line_len[i] / 2), (float)i - (float)data->len_y / 2, (*map)[i][j].z, line);
			init_rotations(&origin, data);
		}
		init_rot(&down, (float)j - ((float)data->line_len[i] / 2), ((float)i - (float)data->len_y / 2) + 1, (*map)[i + 1][j].z, line);
		init_rotations(&down, data);
		draw(&origin, &down, data, line, 0x00ff0000);
		init_origin(&origin, &down);
		i++;
	}
}

bool	draw_map(t_map ***map, t_data *data, t_point *line)
{
	int	i;

	i = 0;
	while (i < data->len_y)
	{
		draw_adjacent(i, map, data, line);
		i++;
	}
	//final_draw(map, data, line);
//	right_line(map, data, line);
	return (true);
}
