/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:04:54 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/20 00:45:49 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	init_angle(t_data *data)
{
	data->angle.angle_x = RA_X;
	data->angle.angle_y = RA_Y;
	data->angle.angle_z = RA_Z;
}

void	init_special_rotations(t_rot *rotation, t_data *data)
{
	
	if (data->angle.angle_y != 0)
		rotate_y(rotation, data);
	if (data->angle.angle_x != 0)
		rotate_x(rotation, data);
	if (data->angle.angle_z != 0)
		rotate_z(rotation, data);
}

void	init_rotations(t_rot *rotation, t_data *data)
{
	if (data->angle.angle_z != 0)
		rotate_z(rotation, data);
	if (data->angle.angle_x != 0)
		rotate_x(rotation, data);
	if (data->angle.angle_y != 0)
		rotate_y(rotation, data);
}

void	rotate_z(t_rot *rot, t_data *data)
{
	float theta;
	float x_tmp;
	float y_tmp;
	float c_theta;
	float s_theta;

	theta = data->angle.angle_z * M_PI / 180;
	c_theta = cos(theta);
	s_theta = sin(theta);
	
	x_tmp = rot->x * c_theta - rot->y * s_theta;
	y_tmp = rot->x * s_theta + rot->y * c_theta;

	rot->x = x_tmp;
	rot->y = y_tmp;
}

void	rotate_y(t_rot *rot, t_data *data)
{
	float theta;
	float x_tmp;
	float z_tmp;
	float c_theta;
	float s_theta;

	theta = data->angle.angle_y * M_PI / 180;
	c_theta = cos(theta);
	s_theta = sin(theta);

	x_tmp = rot->x * c_theta - rot->z * s_theta;
	z_tmp = rot->x * s_theta + rot->z * c_theta;

	rot->x = x_tmp;
	rot->z = z_tmp;
}

void rotate_x(t_rot *rot, t_data *data)
{
	float theta;
	float y_tmp;
	float z_tmp;
	float c_theta;
	float s_theta;

	theta = data->angle.angle_x * M_PI / 180;
	c_theta = cos(theta);
	s_theta = sin(theta);

	y_tmp = rot->y * c_theta - rot->z * s_theta;
	z_tmp = rot->y * s_theta + rot->z * c_theta;

	rot->y = y_tmp;
	rot->z = z_tmp;
}
