/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:25:49 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/07 04:45:51 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void free_all(char *buffer, t_map *map)
{
	int	i;
	
	free(buffer);
	i = 0;
	while (map->plan[i])
	{
		free(map->plan[i]);
		i++;
	}
	free(map->plan);
}
