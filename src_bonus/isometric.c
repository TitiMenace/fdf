/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:47:14 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/18 19:16:46 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

float	get_focal_lenght(float x, float y, float z)
{
	return (sqrt(x * x + y * y + z * z));
}

float	x_projection(t_data *data, float x, float y, float z)
{
	float new_x;
	float focal_lenght;

	z+=40;
	focal_lenght = get_focal_lenght(x, y, z);
	if (focal_lenght == 0)
		focal_lenght = 0.001;
	
	new_x = data->offset * x / focal_lenght;
	//new_x = data->offset * x;
	return (new_x);
}

float	y_projection(t_data *data, float x, float y, float z)
{
	float new_y;
	float focal_lenght;
		
	z+=40;
	focal_lenght = get_focal_lenght(x, y, z);
	if (focal_lenght == 0)
		focal_lenght = 0.001;
	

	//new_y = data->offset * y;
	new_y = data->offset * y / focal_lenght;
	return (new_y);
}
