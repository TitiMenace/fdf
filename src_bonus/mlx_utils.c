/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:34:13 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/28 02:35:53 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	 no_alpha_rendering(t_data *data)
{
	if (data->img.img != 0)
		mlx_destroy_image(data->mlx.mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w\
		, data->mlx.w_h);
	data->img.addr = mlx_get_data_addr(data->img.img\
		, &data->img.bits_per_pixel, &data->img.line_lenght, &data->img.endian);
}
