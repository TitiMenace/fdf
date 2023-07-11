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

void	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.w_w = WIN_WIDTH;
	data->mlx.w_h = WIN_HEIGHT;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_w, \
			data->mlx.w_h, "fdf");
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h);
	data->img.addr = mlx_get_data_addr(data->img.img, \
			&data->img.bits_per_pixel, &data->img.line_lenght, \
			&data->img.endian);
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

void	initializations(t_data *data)
{
	init_mlx(data);
	init_cinematic(data);
	init_offset(data);
	init_color(data);
	init_projections(data);
	init_line(&(data->line), data);
}

int	main(int ac, char **av)
{	
	t_data	data;

	if (ac != 2)
		return (1);
	if (!check_format(av[1]))
		return (write(2, "Incorrect format !\n", 19));
	if (!init_map(av[1], &(data.map), &data))
		return (write(2, "Error\n", 6));
	initializations(&data);
	init_angle(&data);
	rendering(&data);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
	free_map(&data.map, data.len_y);
	free(data.mlx.mlx);
	free(data.line_len);
	return (0);
}
