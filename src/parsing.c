/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:40:23 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/28 03:47:01 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

int	get_line_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			count++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			continue ;
		}
		i++;
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
		if (str[i] == '\n' && isprintable[str[i + 1]])
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
		free(*map[x]);
		x++;
	}
	free(*map);
}

bool	parsing_map(char *buffer, t_map ***map, t_data *data)
{
	int	y;
	int	x;
	int	index;

	data->line_len = malloc(sizeof(int) * get_lines(buffer));
	if (!data->line_len)
		return (false);
	*map = malloc(sizeof(t_map *) * get_lines(buffer));
	if (!*map)
		return (free(data->line_len), false);
	y = 0;
	index = 0;
	while (y < data->line_len)
	{
		*map[y] = malloc(sizeof(t_map) * get_line_len());
		if (!*map[y])
			return (free_map(map, y), false);
		x = 0;
		while (x < get_line_len)
		{
			*map[y][x]->z = ft_atoi(buffer, &index);
			if (buffer[index == ','])
				*map[y][x]->color.hex = get_color(buffer, &index);
			x++;
		}
		y++;
	}
	

}
