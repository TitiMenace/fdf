/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:10:39 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/27 07:12:49 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

bool	draw_map_x(t_map *map, t_mlx *mlx, t_point *line)
{	
	int	i;
	int	j;
	
	//find_start_map(map, line);
	i = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (j + 1 < map->len_x)
		{
			line->a_x = line->start_x + ((j - map->len_x / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i - map->len_y / 2) * (OFFSET + 1));
			line->a_y = line->start_y + ((j - map->len_x / 2) * (OFFSET + 1) * sin(RA_Z) + (i - map->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - map->plan[i][j] * (OFFSET + 1) * sin(RA_X);
			line->b_x = line->start_x + ((j + 1 - map->len_x / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i - map->len_y / 2) * (OFFSET + 1));
			line->b_y = line->start_y + ((j + 1 - map->len_x / 2) * (OFFSET + 1) * sin(RA_Z) + (i - map->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - map->plan[i][j + 1] * (OFFSET + 1) * sin(RA_X);
			if (map->plan[i][j + 1] != 0 || map->plan[i][j] != 0)
				draw_line(mlx, line, 0x3c14dc, map);
			else
				draw_line(mlx, line, 0x507fff, map);

			j++;
		}
		i++;
	}
	return (true);
}

bool	draw_map_y(t_map *map, t_mlx *mlx, t_point *line)
{	
	int	i;
	int	j;
	
	i = 0;
	while (i + 1 < map->len_y)
	{
		j = 0;
		while (j < map->len_x)
		{
			line->a_x = line->start_x + ((j - map->len_x / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i - map->len_y / 2) * (OFFSET + 1));
			line->a_y = line->start_y + ((j - map->len_x / 2) * (OFFSET + 1) * sin(RA_Z) + (i - map->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - map->plan[i][j] * (OFFSET + 1) * sin(RA_X);
			line->b_x = line->start_x + ((j - map->len_x / 2) * (OFFSET + 1)) * cos(RA_Z) - sin(RA_Z) * ((i + 1 - map->len_y / 2) * (OFFSET + 1));
			line->b_y = line->start_y + ((j - map->len_x / 2) * (OFFSET + 1) * sin(RA_Z) + (i + 1 - map->len_y / 2) * (OFFSET + 1) * cos(RA_Z)) * cos(RA_X) - map->plan[i + 1][j] * (OFFSET + 1) * sin(RA_X);
			if (map->plan[i + 1][j] != 0 || map->plan[i][j] != 0)
				draw_line(mlx, line, 0x3c14dc, map);
			else
				draw_line(mlx, line, 0x507fff, map);

			j++;
		}
		i++;
	}
	return (true);
}
