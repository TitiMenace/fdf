/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:32:16 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 00:32:46 by tschecro         ###   ########.fr       */
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
