/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:38:40 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/13 03:58:31 by tschecro         ###   ########.fr       */
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
		data->mlx.w_w = big * OFFSET * 2;
		data->mlx.w_h = data->len_y * OFFSET * 2;
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
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h, "test");
}

void	init_line(t_point *line, t_data *data)
{
	line->start_x = data->mlx.w_w / 2;
	line->start_y = data->mlx.w_h / 2;
}

int	main(int ac, char **av)
{	
	t_data	data;
	t_map	**map;
	t_point	line;
	
	if (ac != 2)
		return (1);
	if	(!check_format(av[1]))
		return (write(2, "Incorrect format !\n", 19));
	if (!init_map(av[1], &map, &data))
		return (write(2, "Error\n", 6));
	init_mlx(&data);
	img_init(&data);
	init_line(&line, &data);
	draw_map_x(&map, &data, &line);
	draw_map_y(&map, &data, &line);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.img.img, 0, 0);
	mlx_loop(data.mlx.mlx);
	return (0);
}
