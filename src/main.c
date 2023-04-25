/************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:15:33 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/14 03:29:35 by tschecro         ###   ########.fr       */
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

void	init_struct(t_mlx *mlx, t_point *line, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	mlx->couleur = (t_color){.b = 120, .g = 90};
	line->a_x = 0;
	line->a_y = 0;
	line->b_x = 0;
	line->b_y = 0;
	line->start_x = WIN_WIDTH / 2;
	line->start_y = WIN_HEIGHT / 2;
	map->len_x = -1;
	map->len_y = 0;
}

int	main(int ac, char **av)
{	
	t_mlx	mlx;
	t_point	line;
	t_map	map;

	(void)ac;
	init_struct(&mlx, &line, &map);
	mlx.couleur = (t_color){.b = 80, .g = 120};
	if (!check_arg(av[1], &map))
		return (write(2, "Error\n", 6));
//	fill_line(&mlx, &line);
	draw_map_x(&map, &mlx, &line);
	draw_map_y(&map, &mlx, &line);
	mlx_loop(mlx.mlx);
	return (0);
}
