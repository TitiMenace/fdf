/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:27:38 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/10 00:28:23 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
