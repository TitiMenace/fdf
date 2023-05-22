/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:47:14 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/22 16:53:41 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

float	x_projection(t_data *data, float x, float y)
{
	float new_x;

	new_x = data->offset * (x - y) * 0.81;
	return (new_x);
}

float	y_projection(t_data *data, float x, float y, float z)
{
	float new_y;

	new_y = data->offset * ((x + y) * 0.81 - z);
	return (new_y);
}
