/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collide_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:12:55 by tschecro          #+#    #+#             */
/*   Updated: 2023/08/22 17:12:57 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "struct.h"
#include "includes.h"

void	get_new_points(t_point *seg, t_point *vectors, t_data *data, float *t)
{
	seg->a_x += (*t * vectors->a_x);
	seg->a_y += (*t * vectors->a_y);
	if (seg->a_x < 0)
		seg->a_x = 0;
	if (seg->a_y < 0)
		seg->a_y = 0;
	if (seg->a_x >= data->mlx.w_w)
		seg->a_x = data->mlx.w_w - 1;
	if (seg->a_y >= data->mlx.w_h)
		seg->a_y = data->mlx.w_h - 1;
}
