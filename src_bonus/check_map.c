/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:57:46 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/26 21:13:52 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

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

char	*get_map(char *arg)
{	
	int		i;
	char	*new_line;
	char	*buffer;
	
	
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
		buffer = ft_strjoin(buffer, new_line);
		free(new_line);
		new_line = get_next_line(i);
	}
	close(i);
	return (free(new_line), buffer);
}

int	ft_atoi(char *buffer, int *index)
{
	int	sign;
	int result;

	while (buffer[*index] == ' ' || buffer[*index] == '\n')
		(*index)++;
	sign = 1;
	if (buffer[*index] == '-')
	{
		sign = -sign;
		(*index)++;
	}
	result = 0;
	while (buffer[*index] >= '0' && buffer[*index] <= '9')
	{
		result = result * 10 + (buffer[*index] - 48);
		(*index)++;
	}
	return (result * sign);
}

bool	init_map(char *file_name, t_map	***map, t_data *data)
{
	char	*buffer;
	
	buffer = get_map(file_name);
	if (!buffer)
		return (false);
	if (!parsing_map(buffer, map, data))
		return (free(buffer), false);
	return (true);
}
