/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:27:38 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/27 23:02:26 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->img.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx);
	free_map(&(data->map), data->len_y);
	free(data->mlx.mlx);
	free(data->line_len);
	exit(EXIT_SUCCESS);
	return(1);

}

static int	loop_hook_handler(t_data *data)
{
	if (data->set_cinematic == true)
		rendering(data);
	return (0);
}

static int	hooks_handler(int zazou, t_data *data)
{
		
	if (zazou == XK_Escape)
		destroy(data);
	set_mods_hooks(data, zazou);
	if (data->set_cinematic == true)
		set_cinematics_hooks(data, zazou);	
	set_movements_hooks(data, zazou);
	set_angles_hooks(data, zazou);
	set_colors_hooks(data, zazou);	
	set_alpha_value_hooks(data, zazou);
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
	//if (data->set_cinematic == true)
	mlx_loop_hook(data->mlx.mlx, loop_hook_handler, data);
}

