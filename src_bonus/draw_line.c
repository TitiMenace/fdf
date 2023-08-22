/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:55:11 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/12 04:53:52 by tschecro         ###   ########.fr       */
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

void	draw_line(t_data *data, t_point *seg)
{
	t_line		utils;
	t_bresen	help;

	if (!truncate_line(seg, data))
		return ;
	init_s_line(&utils);
	utils.dx = ft_abs(seg->b_x - seg->a_x);
	utils.dy = ft_abs(seg->b_y - seg->a_y);
	utils.sx = def_slope(seg->a_x, seg->b_x);
	utils.sy = def_slope(seg->a_y, seg->b_y);
	utils.err = def_error(utils.dx, utils.dy);
	help.t = 0.0;
	if (utils.dx * utils.dx + utils.dy * utils.dy == 0)
		help.dt = 100000000000.; 
	else
		help.dt = 1.0 / (sqrt(utils.dx * utils.dx + utils.dy * utils.dy));
	init_bresen_color(&help, seg, data);
	bresenham(data, seg, &help, &utils);
}
