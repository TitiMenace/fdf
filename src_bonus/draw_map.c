/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:10:39 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/22 15:17:21 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"


void	projections(t_point *line, t_data *data, t_rot *r1, t_rot *r2)
{
	line->a_x = line->start_x + x_projection(data, r1->x, r1->y);
	line->a_y = line->start_y + y_projection(data, r1->x, r1->y, r1->z);
	line->b_x = line->start_x + x_projection(data, r2->x, r2->y);
	line->b_y = line->start_y + y_projection(data, r2->x, r2->y, r2->z);

}

void	init_rot(t_rot *rotate, int x, int y, int z)
{
	rotate->x = x;
	rotate->y = y;
	rotate->z = z;
}

bool	draw_map_x(t_map ***map, t_data *data, t_point *line)
{	
	int	i;
	int	j;
	int	color;
	t_rot	rot_1;
	t_rot	rot_2;

	i = 0;
	while (i < data->len_y)
	{
		j = 0;
		while (j + 1 < data->line_len[i])
		{
			init_rot(&rot_1, j, i, (*map)[i][j].z);
			init_rot(&rot_2, j + 1, i, (*map)[i][j + 1].z);
			init_rotations(&rot_1, data);
			init_rotations(&rot_2, data);
			projections(line, data, &rot_1, &rot_2);
			if ((*map)[i][j + 1].z > ((*map)[i][j].z))
				color = (*map)[i][j + 1].color.hex;
			else
				color = (*map)[i][j].color.hex;
			draw_line(data, line, color);
			j++;
		}
		i++;
	}
	return (true);
}

bool	draw_map_y(t_map ***map, t_data *data, t_point *line)
{	
	int	i;
	int	j;
	int	color;
	t_rot	rot_1;
	t_rot	rot_2;
	
	i = 0;
	while (i + 1 < data->len_y)
	{
		j = 0;
		while (j < data->line_len[i])
		{
			init_rot(&rot_1, j, i, (*map)[i][j].z);
			init_rot(&rot_2, j, i + 1, (*map)[i + 1][j].z);
			init_rotations(&rot_1, data);
			init_rotations(&rot_2, data);
			projections(line, data, &rot_1, &rot_2);
			if ((*map)[i + 1][j].z > ((*map)[i][j].z))
				color = (*map)[i + 1][j].color.hex;
			else
				color = (*map)[i][j].color.hex;
			draw_line(data, line, color);
			j++;
		}
		i++;
	}
	return (true);
}
