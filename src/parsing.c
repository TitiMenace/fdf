/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:40:23 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/10 21:09:28 by tschecro         ###   ########.fr       */
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

