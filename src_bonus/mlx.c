/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 03:23:16 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/21 06:34:07 by tschecro         ###   ########.fr       */
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
	//dprintf(2, "test\n");
	//ft_memset(data->img.addr, 0xFF000000, data->mlx.w_w * data->mlx.w_h);  
	for (int y = 0; y < data->mlx.w_h; y++)
	{
		for (int x = 0; x < data->mlx.w_w; x++)
		{
			my_mlx_pixel_put(data, x, y, 0xFC000000);
		}
	}
}

int color_from_alpha(unsigned int old_color,unsigned  int new_color, float alpha)
{
	char	*old_col;
	char	*new_col;

	old_col = (char *)&old_color;
	new_col = (char *)&new_color;
	unsigned int r = ((old_color << 8) >> 24) * alpha + ((new_color << 8) >> 24) * (1. - alpha);
	unsigned int g = ((old_color << 16) >> 24) * alpha + ((new_color << 16) >> 24) * (1. - alpha);
	unsigned int b = ((old_color << 24) >> 24) * alpha + ((new_color << 24) >> 24) * (1. - alpha);
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int *pixel_addr = ((int *)(data->img.addr) + ((y << 10) + (y << 9) + (y << 8) + (y << 7) + x));
	u_int8_t	test = color >> 24;
	float alpha = (float)test / (float)0xFF;
	//printf("%d  %d  %f\n", color, color >> 24, alpha);
	color = (color << 8) >> 8;
	//t_v3uc	col1 = *((t_v3uc *)&color);
	int old_color = *pixel_addr;
	color = color_from_alpha((unsigned int)old_color, (unsigned int)color, alpha);
	//t_v3uc ccolor = ((*((t_v3uc *)&old_color)) * alpha + col1 * (1. - alpha));
	 //*((int *)(data->img.addr) + ((y << 10) + (y << 9) + (y << 8) + (y << 7) + x)) = color;
	//*pixel_addr = *((t_v3uc *)&ccolor);
	*pixel_addr = color;
	//dprintf(2, "%d %d,%d\n", *pixel_addr, x, y);
}
