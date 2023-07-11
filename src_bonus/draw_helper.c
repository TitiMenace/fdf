/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:31:53 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/11 00:16:57 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	right_line_drawing(t_data *data, t_map ***map, int i, int j)
{
	init_rot(&data->draw_helper.down, (float)j - ((float)data->line_len[i] / 2), ((float)i - (float)data->len_y / 2) + 1, (*map)[i + 1][j].z, (*map)[i + 1][j].color.hex);
	if (data->special_rendering == true)
		init_special_rotations(&data->draw_helper.down, data);
	else
		init_rotations(&data->draw_helper.down, data);
	draw(&data->draw_helper.origin, &data->draw_helper.down, data, &(data->line));
}

void	down_line_drawing(t_data *data, t_map ***map, int i, int j)
{
	if (j + 1 == data->line_len[i])
		return ;// c'etait break avant peut etre passer en bool;
	init_rot(&data->draw_helper.right, ((float)j - (float)data->line_len[i] / 2) + 1, (float)i - (float)data->len_y / 2, (*map)[i][j + 1].z, (*map)[i][j + 1].color.hex);
	if (data->special_rendering == true)
		init_special_rotations(&data->draw_helper.right, data);
	else
		init_rotations(&data->draw_helper.right, data);
	draw(&data->draw_helper.origin, &data->draw_helper.right, data, &(data->line));
}

void	regular_drawing(t_data *data, t_map ***map, int i, int j)
{
	init_rot(&data->draw_helper.right, ((float)j - (float)data->line_len[i] / 2) + 1, (float)i - (float)data->len_y / 2, (*map)[i][j + 1].z, (*map)[i][j + 1].color.hex);
	init_rot(&data->draw_helper.down, (float)j - ((float)data->line_len[i] / 2), ((float)i - (float)data->len_y / 2) + 1, (*map)[i + 1][j].z, (*map)[i][j + 1].color.hex);
	init_rotations(&data->draw_helper.right, data);
	if (data->special_rendering == true)
		init_special_rotations(&data->draw_helper.down, data);
	else
		init_rotations(&data->draw_helper.down, data);
	draw(&data->draw_helper.origin, &data->draw_helper.right, data, &(data->line));
	draw(&data->draw_helper.origin, &data->draw_helper.down, data, &(data->line));
}

void	drawing(t_data *data, t_map ***map, int i, int j)
{
	if (j + 1 == data->line_len[i] && i + 1 != data->len_y)
		right_line_drawing(data, map, i, j);	
	else if (i + 1 == data->len_y)
		down_line_drawing(data, map, i, j);
	else
		regular_drawing(data, map, i, j);
}
