/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:41:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/16 14:27:56 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"


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

bool	draw(t_rot *r1, t_rot *r2, t_data *data,  t_point *line, int color)
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
	while (j + 1 < data->line_len[i])
	{
	if	(j == 0)
	{
		init_rot(&origin, (float)j - ((float)data->line_len[i] / 2), (float)i - (float)data->len_y / 2, (*map)[i][j].z, line);
		init_rotations(&origin, data);
	}
	else
		init_origin(&origin, &right);
	init_rot(&right, ((float)j - (float)data->line_len[i] / 2) + 1, (float)i - (float)data->len_y / 2, (*map)[i][j + 1].z, line);
	init_rot(&down, (float)j - ((float)data->line_len[i] / 2), ((float)i - (float)data->len_y / 2) + 1, (*map)[i + 1][j].z, line);
	init_rotations(&right, data);
	init_rotations(&down, data);
	draw(&origin, &right, data, line, 0xfff);
	draw(&origin, &down, data, line, 0xfff);
	j++;
	}
}


bool	draw_map(t_map ***map, t_data *data, t_point *line)
{
	int	i;
	int	j;
	int color;
	t_rot	rot1;
	t_rot	rot2;

	i = 0;
	while (i + 1 < data->len_y)
	{
		j = 0;
		while (j + 1 < data->line_len[i])
		{
			draw_adjacent(i, map, data, line);
			i++;
		}
	}
}
