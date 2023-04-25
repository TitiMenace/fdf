/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:40:23 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/10 04:49:30 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "struct.h"
#include "includes.h"



void	get_lines(char *buffer, t_map *map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	map->len_y = count;
}

int	get_size(char *buffer)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
		{
			count++;
			while (buffer[i] >= '0' && buffer[i] <= '9')
				i++;
			continue;
		}
		i++;
	}
	return (count);
}

bool	check_size(char *buffer, t_map *map)
{
	if (map->len_x == -1)
	{
		map->len_x = get_size(buffer);
		return (true);
	}
	else
		if (get_size(buffer) != map->len_x)
		{
			return (false);
		}
	return (true);
}


char	*parsing(char *arg, t_map *map)
{	
	int		i;
	char	*new_line;
	char	*buffer;
	
	if (!check_format(arg))	
	{
		return (NULL);
	}
	i = open(arg, O_RDONLY);
	if (i == -1)
	{
		return (NULL);
	}
	new_line = "";
	buffer = NULL;
	new_line = get_next_line(i);
	while (new_line)
	{
		if (!check_chars(new_line) || !check_size(new_line, map))
		{ 
			close(i);
			return (free(new_line), free(buffer), NULL);
		}
		buffer = ft_strjoin(buffer, new_line);
		new_line = get_next_line(i);
	}
	close(i);
	return (free(new_line), buffer);
}

bool	init_map(char *buffer, t_map *map)
{	
	int	i;
	int	tab_index;
	int	j;

	get_lines(buffer, map);
	map->plan = malloc(sizeof(int *) * map->len_y);
	if (!map->plan)
		return (free(buffer), free(map->plan), false);
	tab_index = 0;
	i = 0;
	while (tab_index < map->len_y)
	{
		map->plan[tab_index] = malloc(sizeof(int) * map->len_x);
		if (!map->plan[tab_index])
			return (free_all(buffer, map), false);
		j = 0;
		while (buffer[i] != '\n')
		{
			if (buffer[i] >= '0' && buffer[i] <= '9')
			{
				map->plan[tab_index][j] = get_int(buffer, &i);
				j++;
				continue ;
			}
			i++;
		}
		i++;
		tab_index++;
	}
	return (free(buffer), true);
}
