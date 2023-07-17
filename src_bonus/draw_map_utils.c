/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:31:12 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/11 23:23:27 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	set_init_rot_helper(t_data *data, float x, float y, float z)
{	
	data->rot_hlp.x = x;
	data->rot_hlp.y = y;
	data->rot_hlp.z = z;
}

void	set_origin_point(t_data *data, t_map ***map, int i, int j)
{
	set_init_rot_helper(data, (float)j
		- ((float)data->line_len[0] / 2), (float)i
		- (float)data->len_y / 2, (*map)[i][j].z);
	init_rot(&data->draw_helper.origin, data->rot_hlp, \
			(*map)[i][j].color.hex);
	init_rotations(&data->draw_helper.origin, data);
}

void	init_rot(t_rot *rotate, t_init_r ro, int color)
{
	rotate->x = ro.x;
	rotate->y = ro.y;
	rotate->z = ro.z;
	rotate->col = color;
}
