/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:38:40 by tschecro          #+#    #+#             */
/*   Updated: 2023/07/11 01:35:49 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

bool	init_screen_border(t_data *data)
{
	data->border.high_border.a_x = 0;
	data->border.high_border.a_y = 0;
	data->border.high_border.b_x = data->mlx.w_w;
	data->border.high_border.b_y = 0;
	data->border.right_border.a_x = data->mlx.w_w;
	data->border.right_border.a_y = 0;
	data->border.right_border.b_x = data->mlx.w_w;
	data->border.right_border.b_y = data->mlx.w_h;
	data->border.left_border.a_x = 0;
	data->border.left_border.a_y = 0;
	data->border.left_border.b_x = 0;
	data->border.left_border.b_y = data->mlx.w_h;
	data->border.bottom_border.a_x = 0;
	data->border.bottom_border.a_y = data->mlx.w_h;
	data->border.bottom_border.b_x = data->mlx.w_w;	
	data->border.bottom_border.b_y = data->mlx.w_h;	
	return (true);
}

bool	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	if (WIN_WIDTH <= 0  || WIN_HEIGHT <= 0)
		return (false);
	else
	{
		data->mlx.w_w = WIN_WIDTH;
		data->mlx.w_h = WIN_HEIGHT;
	}
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_w, \
			data->mlx.w_h, "fdf");
	if (!data->mlx.win)
		return (false);
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h);
	if (!data->img.img)
		return (false);
	data->img.addr = mlx_get_data_addr(data->img.img, \
			&data->img.bits_per_pixel, &data->img.line_lenght, \
			&data->img.endian);
	return (true);
}

void	rendering(t_data *data)
{
	if (data->set_cinematic == true)
	{
		data->angle.angle_x = data->angle.angle_x
			- data->cinematic_x * data->cinematic;
		data->angle.angle_y = data->angle.angle_y
			- data->cinematic_y * data->cinematic;
		data->angle.angle_z = data->angle.angle_z
			- data->cinematic_z * data->cinematic;
	}
	img_init(data);
	draw_map(&(data->map), data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
}

bool	initializations(t_data *data)
{
	data->return_value = EXIT_FAILURE;
	if (!init_mlx(data))
		return (false);
	init_cinematic(data);
	init_offset(data);
	init_color(data);
	init_projections(data);
	init_line(&(data->line), data);
	init_screen_border(data);
	return (true);
}

int	main(int ac, char **av)
{	
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac != 2)
		return (1);
	if (!check_format(av[1]))
		return (write(2, "Incorrect format !\n", 19));
	if (!init_map(av[1], &(data.map), &data))
		return (write(2, "Error\n", 6));
	if (!initializations(&data))
	{
		destroy(&data);		
		return (1);
	}
	init_angle(&data);
	rendering(&data);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
