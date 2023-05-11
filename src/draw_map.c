/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:10:39 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/11 03:38:22 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

//0x507fff

bool	draw_map_x(t_map ***map, t_data *data, t_point *line)
{	
	int	i;
	int	j;
	int color1;
	int	color2;
	
	color1 =  0x3c14dc;
	color2 =  0x507fff;


	//find_start_map(map, line);
	i = 0;
	while (i < data->len_y)
	{
		j = 0;
		while (j + 1 < data->line_len[i])
		{
			line->a_x = line->start_x + ((j - data->line_len[i] / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i - data->len_y / 2) * (OFFSET + 1));
			line->a_y = line->start_y + ((j - data->line_len[i] / 2) * (OFFSET + 1) * sin(RA_Z) + (i - data->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - (*map)[i][j].z * (OFFSET + 1) * sin(RA_X);
			line->b_x = line->start_x + ((j + 1 - data->line_len[i] / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i - data->len_y / 2) * (OFFSET + 1));
			line->b_y = line->start_y + ((j + 1 - data->line_len[i] / 2) * (OFFSET + 1) * sin(RA_Z) + (i - data->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - (*map)[i][j + 1].z * (OFFSET + 1) * sin(RA_X);
			if ((*map)[i][j + 1].color.hex != 0)
			{
				color1 = (*map)[i][j + 1].color.hex;
				color2 = (*map)[i][j + 1].color.hex;
			}
			if ((*map)[i][j].color.hex != 0)
			{
				color1 = (*map)[i][j].color.hex;
				color2 = (*map)[i][j].color.hex;
			}
			if ((*map)[i][j + 1].z != 0 || (*map)[i][j].z != 0)
				draw_line(data, line, color1);
			else
				draw_line(data, line, color2);

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
	int	color1;
	int	color2;

	color1 =  0x3c14dc;
	color2 =  0x507fff;
	i = 0;
	while (i + 1 < data->len_y)
	{
		j = 0;
		while (j < data->line_len[i])
		{
			line->a_x = line->start_x + ((j - data->line_len[i] / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i - data->len_y / 2) * (OFFSET + 1));
			line->a_y = line->start_y + ((j - data->line_len[i] / 2) * (OFFSET + 1) * sin(RA_Z) + (i - data->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - (*map)[i][j].z * (OFFSET + 1) * sin(RA_X);
			line->b_x = line->start_x + ((j - data->line_len[i] / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i + 1 - data->len_y / 2) * (OFFSET + 1));
			line->b_y = line->start_y + ((j - data->line_len[i] / 2) * (OFFSET + 1) * sin(RA_Z) + (i + 1 - data->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - (*map)[i + 1][j].z * (OFFSET + 1) * sin(RA_X);
			if ((*map)[i][j].color.hex != 0)
			{
				color1 = (*map)[i][j].color.hex;
				color2 = (*map)[i][j].color.hex;
			}
			if ((*map)[i + 	1][j].color.hex != 0)
			{
				color1 = (*map)[i + 1][j].color.hex;
				color2 = (*map)[i + 1][j].color.hex;
			}


			if ((*map)[i + 1][j].z != 0 || (*map)[i][j].z != 0)
				draw_line(data, line, color1);
			else
				draw_line(data, line, color2);

			j++;
		}
		i++;
	}
	return (true);
}
