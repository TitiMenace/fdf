/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:27:38 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/14 22:08:22 by tschecro         ###   ########.fr       */
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
	if (zazou == XK_Escape)
		destroy(data);
	if (zazou == XK_Up)
		data->offset++;
	if (zazou == XK_Down && data->offset > 0)
		data->offset--;
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

