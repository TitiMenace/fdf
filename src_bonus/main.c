/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:38:40 by tschecro          #+#    #+#             */
/*   Updated: 2023/06/16 14:33:10 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

int	get_biggest_len(t_data *data)
{
	int	i;
	int	big;

	i = 0;
	big = data->line_len[i];
	while (i < data->len_y)
	{
		if (data->line_len[i] > big)
			big = data->line_len[i];
		i++;
	}
	return (big);
}


void	init_mlx(t_data *data)
{
	int	big;

	big = get_biggest_len(data);
	data->mlx.mlx = mlx_init();
	if (WIN_WIDTH == 0 || WIN_HEIGHT == 0)
	{
		data->mlx.w_w = big * data->offset * 2;
		data->mlx.w_h = data->len_y * data->offset * 2;
		if (data->mlx.w_w > 1920 || data->mlx.w_h > 1080)
		{
			data->mlx.w_w = 1920;
			data->mlx.w_h = 1080;
		}
	}
	else
	{
		data->mlx.w_w = WIN_WIDTH;
		data->mlx.w_h = WIN_HEIGHT;
	}
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h, "fdf");
	data->img.img = 0;
	data->get_color = get_red;
}

void	init_offset(t_data *data)
{
	data->offset = OFFSET + 1;
}

void	init_line(t_point *line, t_data *data)
{
	line->start_x = data->mlx.w_w / 2;
	line->start_y = data->mlx.w_h / 2;
}

void	rendering(t_data *data)
{
	img_init(data);
	draw_map(&(data->map), data, &(data->line));
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
}


int	main(int ac, char **av)
{	
	t_data	data;
	
	if (ac != 2)
		return (1);
	if	(!check_format(av[1]))
		return (write(2, "Incorrect format !\n", 19));
	if (!init_map(av[1], &(data.map), &data))
		return (write(2, "Error\n", 6));
	init_offset(&data);
	init_mlx(&data);
	init_line(&(data.line), &data);
	init_angle(&data);
	rendering(&data);	
	init_hooks(&data);	
	mlx_loop(data.mlx.mlx);
	return (0);
}
