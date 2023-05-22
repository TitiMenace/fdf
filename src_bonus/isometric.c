/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:47:14 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/22 23:58:27 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

float	x_projection(t_data *data, float x, float y)
{
	float new_x;

	(void)y;
	new_x = data->offset * x;
	return (new_x);
}

float	y_projection(t_data *data, float x, float y, float z)
{
	float new_y;

	(void)x;
	(void)z;
	new_y = data->offset * y;
	dprintf(2, "%f\n", data->offset);
	return (new_y);
}
