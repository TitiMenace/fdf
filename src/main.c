/************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:15:33 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/28 03:47:18 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes.h"
#include "struct.h"

static int	hooks_handler(int keycode, t_mlx *mlx)
{
	static unsigned int	i;

	if (keycode == XK_Up)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, 1920 / 2 - i, 1080 / 2, mlx->couleur.hex);
		mlx_pixel_put(mlx->mlx, mlx->win, 1920 / 2 + i, 1080 / 2, mlx->couleur.hex);
		i = i + 1;
	}
	if (keycode == XK_Down && i > 0)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, 1920 / 2 - i, 1080 / 2, 0);
		mlx_pixel_put(mlx->mlx, mlx->win, 1920 / 2 + i, 1080 / 2, 0);
		i = i - 1;
	}
	return (1);
}


void	init_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, KeyPress, KeyPressMask, hooks_handler, mlx);
}


int find_start_map(t_map *map, t_point *line)
{	
	if (map->len_x % 2 == 0)
		line->start_x = line->start_x - (OFFSET / 2);
	line->start_x = line->start_x - (OFFSET * (map->len_x / 2));
	if (map->len_y % 2 == 0)
		line->start_y = line->start_y - (OFFSET / 2);
	line->start_y = line->start_y - (OFFSET * (map->len_y / 2));
	return (1);
}

void	init_mlx(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	if (WIN_WIDTH == 0 || WIN_HEIGHT == 0)
	{
		mlx->w_w = map->len_x * OFFSET * 2;
		mlx->w_h = map->len_y * OFFSET * 2;
	}
	else
	{
		mlx->w_w = WIN_WIDTH;
		mlx->w_h = WIN_HEIGHT;
	}
	mlx->win = mlx_new_window(mlx->mlx, mlx->w_w, mlx->w_h, "test");
	mlx->couleur = (t_color){.b = 120, .g = 90};
}

void	init_line(t_point *line, t_mlx *mlx)
{
	line->a_x = 0;
	line->a_y = 0;
	line->b_x = 0;
	line->b_y = 0;
	line->start_x = mlx->w_w / 2;
	line->start_y = mlx->w_h / 2;
}

int	main(int ac, char **av)
{	
	t_data	data;
	t_map	**map;
	
	if (ac != 2)
		return (1);
	if	(!check_format[av[1]])
		return (write(STDERR, "Incorrect format !\n", 19));
	if (!init_map(av[1], &map, &data))
		return (write(2, "Error\n", 6));
	init_mlx(&mlx, &map);
	init_line(&line, &mlx);
	draw_map_x(&map, &mlx, &line);
	draw_map_y(&map, &mlx, &line);
	mlx_loop(mlx.mlx);
	return (0);
}
