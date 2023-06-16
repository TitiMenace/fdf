/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:27:38 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/16 10:43:23 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx);
	free_map(&(data->map), data->len_y - 1);
	free(data->mlx.mlx);
	exit(EXIT_SUCCESS);
	return(1);

}

static int	hooks_handler(int zazou, t_data *data)
{
/*	if (data->angle.angle_x >= 360 || data->angle.angle_x <= -360)
		data->angle.angle_x = 0;
	if (data->angle.angle_y >= 360 || data->angle.angle_y <= -360)
		data->angle.angle_y = 0;
	if (data->angle.angle_z >= 360 || data->angle.angle_z <= -360)
		data->angle.angle_z = 0;
		*/
	if (zazou == XK_Escape)
		destroy(data);
	if (zazou == XK_Return)
		data->offset = data->offset * 1.1;
	if (zazou == XK_BackSpace && data->offset > 0)
		data->offset = data->offset * 0.9;
	if (zazou == XK_Up)
		data->line.start_y = data->line.start_y - 1; 
	if (zazou == XK_Down)
		data->line.start_y = data->line.start_y + 1; 
	if (zazou == XK_Left)
		data->line.start_x = data->line.start_x - 1; 
	if (zazou == XK_Right)
		data->line.start_x = data->line.start_x + 1;
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
	rendering(data);
	return (1);
}

int	cross_button(t_data *data)
{
	destroy(data);
	return (1);
}


void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 17, (1L << 17), cross_button, data);
	mlx_hook(data->mlx.win, 2, KeyPressMask, hooks_handler, data);
}

