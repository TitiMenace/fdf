/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:40:43 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/28 03:29:37 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	set_origin_point(t_data *data)
{
	if	(j == 0)
	{
		init_rot(&origin, (float)j - ((float)data->line_len[i] / 2), (float)i - (float)data->len_y / 2, (*map)[i][j].z, (*map)[i][j].color.hex);
		init_rotations(&origin, data);
	}
	else
		init_origin(&origin, &right);

}
