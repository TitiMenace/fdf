/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:55:11 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/11 02:19:45 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fdf.h"
#include "includes.h"


static int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

static void	init_s_line(t_line *utils)
{
	utils->dx = 0; 
	utils->dy = 0;
	utils->sx = 0;
	utils->sy = 0;
	utils->err = 0;
	utils->err2 = 0;

}

static int	def_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

static int	def_error(int a, int b)
{
	if (a > b)
		return (a / 2);
	else
		return (-b / 2);
}
void	draw_line(t_data *data, t_point *seg, int couleur)
{
	t_line	utils;
	int	err2;

	init_s_line(&utils);
	utils.dx = ft_abs((int)seg->b_x - (int)seg->a_x);
	utils.dy = ft_abs((int)seg->b_y - (int)seg->a_y);
	utils.sx = def_slope((int)seg->a_x, (int)seg->b_x);
	utils.sy = def_slope((int)seg->a_y, (int)seg->b_y);
	utils.err = def_error(utils.dx, utils.dy);
	while (((int)seg->a_x != (int)seg->b_x || (int)seg->a_y != (int)seg->b_y) && (seg->a_x >= 0 && seg->a_x <= data->mlx.w_w) && (seg->a_y >= 0 && seg->a_y <= data->mlx.w_h))
	{
		if ((seg->a_x >= 0 && seg->a_x <= data->mlx.w_w) && (seg->a_y >= 0 && seg->a_y <= data->mlx.w_h))
			mlx_pixel_put(data->mlx.mlx, data->mlx.win, (int)seg->a_x, (int)seg->a_y, couleur);
		err2 = utils.err;
		if (err2 > -utils.dx)
		{
			utils.err -= utils.dy;
			seg->a_x += utils.sx;
		}
		if (err2 < utils.dy)
		{
			utils.err += utils.dx;
			seg->a_y += utils.sy;
		}
	}
}
