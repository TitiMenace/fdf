/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:57:46 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/07 05:46:15 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

bool	check_chars(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (false);
	}
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || (s[i] >= '0' && s[i] <= '9')))
			return (false);
		i++;
	}
	return (true);
}

bool	check_format(char *file_name)
{	
	int	i;

	i = ft_strlen(file_name);
	while(file_name[i] != '.')
		i--;
	if (ft_strcmp(&file_name[i], ".fdf") != 0)
		return (false);
	return (true);
}

bool	check_arg(char *arg, t_map *map)
{	
	char	*buffer;

	buffer = parsing(arg, map);
	if (!buffer)
	{
		return (false);
	}
	if (!init_map(buffer, map))
		return (false);
	
	return (true);
}

int	get_int(char *buffer, int *i)
{
	int sign;
	long result;

	sign = 1;
	result = 0;
	if (buffer[*i] == '-')
	{
		sign = -sign;
		(*i)++;
	}
	while (buffer[*i] >= '0' && buffer[*i] <= '9')
	{
		result = result * 10 + (buffer[*i] - 48);
		(*i)++;
	}
	return (result * sign);
}
