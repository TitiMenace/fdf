/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cinematic_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:40:08 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 06:03:13 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	set_mods_hooks(t_data *data, int zazou)
{
	if (zazou == XK_i)
		data->set_cinematic = !data->set_cinematic;
	if (zazou == XK_p)
		data->isometric = !data->isometric;
	if (zazou == XK_m)
		data->special_rendering = !data->special_rendering;
	if (zazou == XK_u)
		data->set_alpha_mode = !data->set_alpha_mode;
	if (zazou == XK_n)
		data->fast_mode = !data->fast_mode;
}

void	set_movements_hooks(t_data *data, int zazou)
{
	if (zazou == XK_Return)
		data->offset = data->offset * 1.1;
	if (zazou == XK_BackSpace && data->offset > 0)
		data->offset = data->offset * 0.9;
	if (zazou == XK_Up)
		data->line.start_y = data->line.start_y - 10;
	if (zazou == XK_Down)
		data->line.start_y = data->line.start_y + 10;
	if (zazou == XK_Left)
		data->line.start_x = data->line.start_x - 10;
	if (zazou == XK_Right)
		data->line.start_x = data->line.start_x + 10;
	if (data->isometric == false)
	{
		if (zazou == XK_y)
			data->fov += 1;
		if (zazou == XK_t)
			data->fov -= 1;
	}
}

void	set_cinematics_hooks(t_data *data, int zazou)
{
	if (zazou == XK_e && data->cinematic_x >= -1)
		data->cinematic_x -= 0.1;
	if (zazou == XK_r && data->cinematic_x <= 1)
		data->cinematic_x += 0.1;
	if (zazou == XK_d && data->cinematic_y >= -1)
		data->cinematic_y -= 0.1;
	if (zazou == XK_f && data->cinematic_y <= 1)
		data->cinematic_y += 0.1;
	if (zazou == XK_c && data->cinematic_z >= -1)
		data->cinematic_z -= 0.1;
	if (zazou == XK_v && data->cinematic_z <= 1)
		data->cinematic_z += 0.1;
	if (zazou == XK_k && data->cinematic >= 0)
		data->cinematic -= 0.1;
	if (zazou == XK_l && data->cinematic <= 1)
		data->cinematic += 0.1;
}

void	set_angles_hooks(t_data *data, int zazou)
{
	if (zazou == XK_q)
		data->angle.angle_x -= 5;
	if (zazou == XK_w)
		data->angle.angle_x += 5;
	if (zazou == XK_a)
		data->angle.angle_y -= 5;
	if (zazou == XK_s)
		data->angle.angle_y += 5;
	if (zazou == XK_z)
		data->angle.angle_z -= 5;
	if (zazou == XK_x)
		data->angle.angle_z += 5;
}
