/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:40:23 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/26 23:48:45 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

int	get_line_len(char *str, int i)
{
	int	count;

	i = 0;
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
			continue;
		}
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

	data->len_y = get_lines(buffer);
	data->line_len = malloc(sizeof(int) * data->len_y);
	if (!data->line_len)
		return (false);
	*map = malloc(sizeof(t_map *) * data->len_y);
	if (!*map)
		return (free(data->line_len), false);
	y = 0;
	index = 0;
	while (y < data->len_y)
	{
		(*map)[y] = malloc(sizeof(t_map) * get_line_len(buffer, index));
		if (!(*map)[y])
			return (free_map(map, y), false);
		data->line_len[y] = get_line_len(buffer, index);
		x = 0;
		while (x < data->line_len[y])
		{
			(*map)[y][x].z = ft_atoi(buffer, &index);
			if (y == 0 && x == 0)
			{
				data->z_max = (*map)[y][x].z;
				data->z_min = (*map)[y][x].z;
			}
			else
			{
				if ((*map)[y][x].z >= data->z_max)
					data->z_max = (*map)[y][x].z;
				else if ((*map)[y][x].z <= data->z_min)
					data->z_min = (*map)[y][x].z;
			}
			if (buffer[index] == ',')
			{
				while (buffer[index - 1] != 'x')
					index++;
				(*map)[y][x].color.hex = ft_atohex(&buffer[index]);
				while (buffer[index] != ' ' && buffer[index] != '\n')
					index++;
			}
			else
				(*map)[y][x].color.hex = 0;
			x++;
		}
		y++;
	}
	free(buffer);
	return (true);
}
