/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:47:14 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 06:01:18 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

float	get_focal_lenght(float x, float y, float z)
{
	return (sqrt(x * x + y * y + z * z));
}

float	x_projection(t_data *data, float x, float z)
{
	float	new_x;

	z += data->fov;
	if (z == 0)
		z = 0.001;
	if (data->isometric == true)
		new_x = x * data->offset;
	else
		new_x = x * (data->offset / z);
	return (new_x);
}

float	y_projection(t_data *data, float y, float z)
{
	float	new_y;

	z += data->fov;
	if (z == 0)
		z = 0.001;
	if (data->isometric == true)
		new_y = y * data->offset;
	else
		new_y = y * (data->offset / z);
	return (new_y);
}
