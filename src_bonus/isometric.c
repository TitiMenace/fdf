/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:47:14 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/16 14:57:22 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

float	x_projection(t_data *data, float x, float y, float z)
{
	float new_x;

//	(void)z;
	(void)y;
	new_x = data->offset * x;
	return (new_x + z * 20);
}

float	y_projection(t_data *data, float x, float y, float z)
{
	float new_y;

//	(void)z;
	(void)x;
	new_y = data->offset * y;
	return (new_y + z * 20);
}
