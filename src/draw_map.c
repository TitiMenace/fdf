/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:10:39 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/14 21:19:53 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

bool	draw_map_x(t_map ***map, t_data *data, t_point *line)
{	
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < data->len_y)
	{
		j = 0;
		while (j + 1 < data->line_len[i])
		{
			line->a_x = line->start_x + ((j - data->line_len[i] / 2) * data->offset) * cos(RA_Z) - sin(RA_Z) * ((i - data->len_y / 2) * data->offset);
			line->a_y = line->start_y + ((j - data->line_len[i] / 2) * data->offset * sin(RA_Z) + (i - data->len_y / 2) * data->offset * cos(RA_Z)) * cos(RA_X) - (*map)[i][j].z * data->offset * sin(RA_X);
			line->b_x = line->start_x + ((j + 1 - data->line_len[i] / 2) * data->offset) * cos(RA_Z) - sin(RA_Z) * ((i - data->len_y / 2) * data->offset);
			line->b_y = line->start_y + ((j + 1 - data->line_len[i] / 2) * data->offset * sin(RA_Z) + (i - data->len_y / 2) * data->offset * cos(RA_Z)) * cos(RA_X) - (*map)[i][j + 1].z * data->offset * sin(RA_X);
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

	i = 0;
	while (i + 1 < data->len_y)
	{
		j = 0;
		while (j < data->line_len[i])
		{
			line->a_x = line->start_x + ((j - data->line_len[i] / 2) * data->offset) * cos(RA_Z) - sin(RA_Z) * ((i - data->len_y / 2) * data->offset);
			line->a_y = line->start_y + ((j - data->line_len[i] / 2) * data->offset * sin(RA_Z) + (i - data->len_y / 2) * data->offset * cos(RA_Z)) * cos(RA_X) - (*map)[i][j].z * data->offset * sin(RA_X);
			line->b_x = line->start_x + ((j - data->line_len[i] / 2) * data->offset) * cos(RA_Z) - sin(RA_Z) * ((i + 1 - data->len_y / 2) * data->offset);
			line->b_y = line->start_y + ((j - data->line_len[i] / 2) * data->offset * sin(RA_Z) + (i + 1 - data->len_y / 2) * data->offset * cos(RA_Z)) * cos(RA_X) - (*map)[i + 1][j].z * data->offset * sin(RA_X);
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
