/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 03:23:16 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/28 02:36:23 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

void	ft_memset(void *ptr, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((int *)ptr)[i] = (int)value;
		i++;
	}
}


void	img_init(t_data	*data)
{
	unsigned int	alpha;
	int				y;
	int				x;
	
	if (data->set_alpha_mode == false)
		no_alpha_rendering(data);	
	else
	{
		alpha = (data->alpha << 24);
		y = 0;
		while (y < data->mlx.w_h)
		{
			x = 0;
			while (x < data->mlx.w_w)
			{
				my_mlx_pixel_put(data, x, y, alpha);
				x++;
			}
			y++;
		}
	}
}

int color_from_alpha(unsigned int old_color,unsigned  int new_color, float alpha)
{
	char	*old_col;
	char	*new_col;
	t_rgb	alpha_tmp;

	old_col = (char *)&old_color;
	new_col = (char *)&new_color;
	alpha_tmp.r = ((old_color << 8) >> 24) * alpha + ((new_color << 8) >> 24) * (1. - alpha);
	alpha_tmp.g = ((old_color << 16) >> 24) * alpha + ((new_color << 16) >> 24) * (1. - alpha);
	alpha_tmp.b = ((old_color << 24) >> 24) * alpha + ((new_color << 24) >> 24) * (1. - alpha);
	return (alpha_tmp.r << 16 | alpha_tmp.g << 8 | alpha_tmp.b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int 		*pixel_addr;
	u_int8_t	test;
	float		alpha;
	int			old_color;
	
	pixel_addr = ((int *)(data->img.addr)\
	+ ((y << 10) + (y << 9) + (y << 8) + (y << 7) + x));
	test = color >> 24;
	alpha = (float)test / (float)0xFF;
	color = (color << 8) >> 8;
	old_color = *pixel_addr;
	color = color_from_alpha((unsigned int)old_color\
	, (unsigned int)color, alpha);
	*pixel_addr = color;
}
