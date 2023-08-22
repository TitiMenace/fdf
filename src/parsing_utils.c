/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:55:52 by tschecro          #+#    #+#             */
/*   Updated: 2023/08/22 17:00:58 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

bool	parsing_malloc(int *len, int *y, t_map ***map, t_data *data)
{
	if (*len < 0)
		return (free_map(map, *y), false);
	(*map)[*y] = malloc(sizeof(t_map) * *len);
	if (!(*map)[*y])
		return (free_map(map, *y), false);
	data->line_len[*y] = *len;
	return (true);
}

void	get_line_len_utils(char *str, int *i, int *count)
{
	if (str[*i] == '-')
		(*i)++;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		(*count)++;
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
}

void	set_z_range(t_data *data, t_map ***map, int y, int x)
{
	if (y == 0 && x == 0)
	{
		data->z_max = (*map)[0][0].z;
		data->z_min = (*map)[0][0].z;
	}
	else
	{
		if ((*map)[y][x].z >= data->z_max)
			data->z_max = (*map)[y][x].z;
		else if ((*map)[y][x].z <= data->z_min)
			data->z_min = (*map)[y][x].z;
	}
}

void	get_map_color_hex(char *buffer, int *index, int *hex_color)
{
	if (buffer[*index] == ',')
	{
		while (buffer[*index - 1] != 'x')
			(*index)++;
		*hex_color = ft_atohex(&buffer[*index]);
		while (buffer[*index] != ' ' && buffer[*index] != '\n')
			(*index)++;
	}
	else
		*hex_color = 0;
}

bool	map_allocation(t_data *data, char *buffer, t_map ***map)
{
	data->len_y = get_lines(buffer);
	data->line_len = malloc(sizeof(int) * data->len_y);
	if (!data->line_len)
		return (false);
	*map = malloc(sizeof(t_map *) * data->len_y);
	if (!*map)
		return (free(data->line_len), false);
	ft_bzero(*map, data->len_y * sizeof(t_map *));
	return (true);
}
