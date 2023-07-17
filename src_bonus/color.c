/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:24:44 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/11 01:27:49 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fdf.h"
#include "includes.h"

unsigned int	get_interpolated_color(t_data *data, unsigned int start_color \
		, unsigned int end_color, double t)
{
	t_inter	colors;

	(void)data;
	colors.start_r = (start_color >> 16) & 0xFF;
	colors.start_g = (start_color >> 8) & 0xFF;
	colors.start_b = start_color & 0xFF;
	colors.end_r = (end_color >> 16) & 0xFF;
	colors.end_g = (end_color >> 8) & 0xFF;
	colors.end_b = end_color & 0xFF;
	colors.r = (float)(colors.start_r + (colors.end_r - colors.start_r) * t);
	colors.g = (float)(colors.start_g + (colors.end_g - colors.start_g) * t);
	colors.b = (float)(colors.start_b + (colors.end_b - colors.start_b) * t);
	return ((colors.r << 16) | (colors.g << 8) | colors.b);
}

float	max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	argb_to_int(int a, int r, int g, int b)
{
	return ((a << 24) + (r << 16) + (g << 8) + b);
}

int	get_point_color(t_data *data, float z_origin, float z_rotated)
{	
	float	z;	

	(void)data;
	(void)z_rotated;
	z = z_origin;
	z += 20;
	z = max(z, 0.);
	z = min(z, 40.);
	z /= 40.;
	z *= 255;
	return (argb_to_int(0, z, 0, 255 - z));
}
