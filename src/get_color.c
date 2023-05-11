/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:50:52 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/11 03:11:06 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

int	strhexlen(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != ' ')
		i++;
	return (i);
}

bool	ishexdigit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') 
			|| (c >= 'A' && c <= 'F'));
}

int	ft_atohex(char *buffer)
{
	int	hex;
	int len;
	int	i;

	len = strhexlen(buffer);
	hex = 0;
	i = 0;
	while (buffer[i] != ' ')
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
			hex += (buffer[i] - 48) * pow(16, len - 1 - (i));
		else if (buffer[i] >= 'a' && buffer[i] <= 'f')
			hex += (buffer[i] - 'a' + 10) * pow(16, len - 1 - (i));
		else if (buffer[i] >= 'A' && buffer[i] <= 'F')
			hex += (buffer[i] - 'A' + 10) * pow(16, len - 1 - (i));
		(i)++;
	}
	return (hex);
}
