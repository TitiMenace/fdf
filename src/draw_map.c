/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:10:39 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/14 03:58:12 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

bool	draw_map_x(t_map *map, t_mlx *mlx, t_point *line)
{	
	int	i;
	int	j;
	
	find_start_map(map, line);
	i = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (j + 1 < map->len_x)
		{
			line->a_x = line->start_x + ((j * (OFFSET + 1)) * cos(RA_Y) + (i * (OFFSET + 1)) * sin(RA_X) * sin(RA_Y) - (map->plan[i][j] * (OFFSET + 1)) * cos(RA_X) * sin(RA_Y));
			line->a_y = line->start_y + ((i * (OFFSET + 1)) * cos(RA_X) + (map->plan[i][j] * (OFFSET + 1)) * sin(RA_X));
			line->b_x = line->start_x + (((j + 1) * (OFFSET + 1)) * cos(RA_Y) + (i * (OFFSET + 1)) * sin(RA_X) * sin(RA_Y) - (map->plan[i][j + 1] * OFFSET) * cos(RA_X) * sin(RA_Y));
			line->b_y = line->start_y + ((i * (OFFSET + 1)) * cos(RA_X) + (map->plan[i][j + 1] * (OFFSET + 1)) * sin(RA_X));
			if (map->plan[i][j + 1] != 0 || map->plan[i][j] != 0)
				draw_line(mlx, line, 0x3c14dc);
			else
				draw_line(mlx, line, 0x507fff);

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
			line->a_x = line->start_x + ((j * (OFFSET + 1)) * cos(RA_Y) + (i * (OFFSET + 1)) * sin(RA_X) * sin(RA_Y) - (map->plan[i][j] * (OFFSET + 1)) * cos(RA_X) * sin(RA_Y));
			line->a_y = line->start_y + ((i * OFFSET) * cos(RA_X) + (map->plan[i][j] * OFFSET) * sin(RA_X));
			line->b_x = line->start_x + ((j  * (OFFSET + 1)) * cos(RA_Y) + ((i + 1) * (OFFSET + 1)) * sin(RA_X) * sin(RA_Y) - (map->plan[i + 1][j] * (OFFSET + 1)) * cos(RA_X) * sin(RA_Y));
			line->b_y = line->start_y + (((i + 1) * (OFFSET + 1)) * cos(RA_X) + (map->plan[i + 1][j] * (OFFSET + 1)) * sin(RA_X));
		
			if (map->plan[i + 1][j] != 0 || map->plan[i][j] != 0)
				draw_line(mlx, line, 0x3c14dc);
			else
				draw_line(mlx, line, 0x507fff);

			j++;
		}
		i++;
	}
	return (true);
}
