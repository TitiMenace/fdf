/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 03:23:16 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/13 03:36:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	img_init(t_data	*data)
{
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_lenght, &data->img.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	 char * dst;

	 dst = data->img.addr + (y * data->img.line_lenght + x * (data->img.bits_per_pixel / 8));
	 *(unsigned int *)dst = color;
}
