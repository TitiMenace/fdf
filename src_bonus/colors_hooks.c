/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:55:50 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/27 22:58:35 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	set_alpha_value_hooks(t_data *data, int zazou)
{
	if (zazou == XK_h && data->alpha + 10 <= 255)
		data->alpha += 10;
	if (zazou == XK_j && data->alpha - 10 >= 0)
		data->alpha -= 10;
}

void	set_colors_hooks(t_data *data, int zazou)
{
	if (zazou == XK_g)
	{
		if(data->end_color == 0x00FF00FF)
		{
			data->start_color = 0x000000FF;
			data->end_color = 0x0000FFFF;
		}
		else if (data->start_color == 0x000000FF)
		{
			data->start_color = 0x00FF0000;
			data->end_color = 0x00FFFF00;
		}
		else if (data->start_color == 0x00FF0000)
		{
			data->start_color = 0x007F00FF;
			data->end_color = 0x00FF007F;
		}
		else
		{
			data->start_color = 0x00FF00FF;
			data->end_color = 0x00FF00FF;
		}
	}
}


