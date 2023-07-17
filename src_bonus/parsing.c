/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:40:23 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 01:08:51 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

int	get_line_len(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] != '\n')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			count++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i] == ',')
		{
			while (str[i] != ' ' && str[i] != '\n')
				i++;
			continue ;
		}
		if (str[i] != ' ' && str[i] != '\n'
				&& (str[i] < 0  || str[i] > 9) && str[i] != '-')
			return (-1);
	}
	return (count);
}

bool	isprintable(char c)
{
	if (c == ' ' || c == '-' || (c >= '0' && c <= '9'))
		return (true);
	else
		return (false);
}

int	get_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n' && isprintable(str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

void	free_map(t_map ***map, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{
		free((*map)[x]);
		x++;
	}
	free(*map);
}

bool	parsing_map(char *buffer, t_map ***map, t_data *data)
{
	int	y;
	int	x;
	int	index;
	int	len;

	if (!map_allocation(data, buffer, map))
		return (false);
	y = 0;
	index = 0;
	while (y < data->len_y)
	{
		len = get_line_len(buffer, index);
		if (len < 0)
			return (free_map(map, y), false);
		(*map)[y] = malloc(sizeof(t_map) * len);
		if (!(*map)[y])
			return (free_map(map, y), false);
		data->line_len[y] = len;
		x = 0;
		while (x < data->line_len[y])
		{
			(*map)[y][x].z = ft_atoi(buffer, &index);
			set_z_range(data, map, y, x);
			get_map_color_hex(buffer, &index, &(*map)[y][x].color.hex);
			x++;
		}
		y++;
	}
	return (true);
}
