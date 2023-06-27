/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 03:18:04 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/27 03:22:24 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	init_cinematic(t_data *data)
{
	data->cinematic = 1;
	data->cinematic_x = 0;
	data->cinematic_y = 0;
	data->cinematic_z = 0;
	data->set_cinematic = false;
}

void	init_color(t_data *data)
{
	data->start_color = 0x00FFFFFF;
	data->end_color = 0;
	data->set_alpha_mode = false;
	data->alpha = 0;
}

void	init_projections(t_data *data)
{
	data->fov = 30;
	data->special_rendering = false;
	data->isometric = true;
}

void	init_offset(t_data *data)
{
	data->offset = OFFSET + 1;
}

void	init_line(t_point *line, t_data *data)
{
	line->start_x = data->mlx.w_w / 2;
	line->start_y = data->mlx.w_h / 2;
}
