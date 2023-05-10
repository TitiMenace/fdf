/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:50:52 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/10 04:39:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

int	strhexlen(char *buffer, int index)
{
	int	count;

	count = 0;
	while (buffer[index] != ' ')
	{
		count++;
		index++;
	}
	return (count);
}

bool	ishexdigit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') 
			|| (c >= 'A' && c <= 'F'));
}

int	ft_atohex(char *buffer, int	*index)
{
	int	i;
	int	hex;
	int len;

	len = strhexlen(buffer, *index);
	hex = 0;
	i = 0;
	while (buffer[(*index) - 1] != 'x')
		(*index)++;
	while (buffer[*index] != ' ')
	{
		if (buffer[*index] >= '0' && buffer[*index] <= '9')
			hex += (buffer[*index] - 48) * pow(16, len - 1 - (*index));
		else if (buffer[*index] >= 'a' && buffer[*index] <= 'f')
			hex += (buffer[*index] - 'a' + 10) * pow(16, len - 1 - (*index));
		else if (buffer[*index] >= 'A' && buffer[*index] <= 'F')
			hex += (buffer[*index] - 'A' + 10) * pow(16, len - 1 - (*index));
		(*index)++;
	}
	return (hex);
}
