/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:31:53 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 01:14:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	right_line_drawing(t_data *data, t_map ***map, int i, int j)
{
	set_init_rot_helper(data, (float)j
		- ((float)data->line_len[0] / 2), ((float)i
			- (float)data->len_y / 2) + 1, (*map)[i + 1][j].z);
	init_rot(&data->draw_helper.down, data->rot_hlp, \
		(*map)[i + 1][j].color.hex);
	if (data->special_rendering == true)
		init_special_rotations(&data->draw_helper.down, data);
	else
		init_rotations(&data->draw_helper.down, data);
	draw(&data->draw_helper.origin, &data->draw_helper.down, \
		data, &(data->line));
}

bool	down_line_drawing(t_data *data, t_map ***map, int i, int j)
{
	if (j + 1 == data->line_len[i])
		return (false);
	set_init_rot_helper(data, (float)j
		- ((float)data->line_len[0] / 2) + 1, (float)i
		- (float)data->len_y / 2, (*map)[i][j + 1].z);
	init_rot(&data->draw_helper.right, data->rot_hlp, \
		(*map)[i][j + 1].color.hex);
	if (data->special_rendering == true)
		init_special_rotations(&data->draw_helper.right, data);
	else
		init_rotations(&data->draw_helper.right, data);
	draw(&data->draw_helper.origin, &data->draw_helper.right, \
		data, &(data->line));
	return (true);
}

void	regular_drawing(t_data *data, t_map ***map, int i, int j)
{
	set_init_rot_helper(data, (float)j
		- ((float)data->line_len[0] / 2) + 1, (float)i
		- (float)data->len_y / 2, (*map)[i][j + 1].z);
	init_rot(&data->draw_helper.right, data->rot_hlp, \
		(*map)[i][j + 1].color.hex);
	set_init_rot_helper(data, (float)j
		- ((float)data->line_len[0] / 2), ((float)i
			- (float)data->len_y / 2) + 1, (*map)[i + 1][j].z);
	init_rot(&data->draw_helper.down, data->rot_hlp, \
		(*map)[i + 1][j].color.hex);
	init_rotations(&data->draw_helper.right, data);
	if (data->special_rendering == true)
		init_special_rotations(&data->draw_helper.down, data);
	else
		init_rotations(&data->draw_helper.down, data);
	draw(&data->draw_helper.origin, &data->draw_helper.right, \
		data, &(data->line));
	if (j < data->line_len[i + 1])
	{
		draw(&data->draw_helper.origin, &data->draw_helper.down, \
			data, &(data->line));
	}
}

bool	drawing(t_data *data, t_map ***map, int i, int j)
{
	if (j + 1 == data->line_len[i] && i + 1 != data->len_y)
	{
		if (j < data->line_len[i + 1])
			right_line_drawing(data, map, i, j);
	}
	else if (i + 1 == data->len_y)
	{
		if (!down_line_drawing(data, map, i, j))
			return (false);
	}
	else
		regular_drawing(data, map, i, j);
	return (true);
}
