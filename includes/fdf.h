/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:08:12 by tschecro          #+#    #+#             */
/*   Updated: 2023/04/27 06:13:22 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "struct.h"
#include "includes.h"
#include "../lib/minilibx-linux/mlx.h"

/* -------------------------------------------------------------------------- */
/*                      FILE = src/get_next_line_utils.c                      */
/* -------------------------------------------------------------------------- */
char	*ft_strndup(char *str);
int	check_buff(char *buffer, char c);
char	*ft_strjoin(char *remain, char *buffer);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/main.c                              */
/* -------------------------------------------------------------------------- */
void	init_hooks(t_mlx *mlx);
int find_start_map(t_map *map, t_point *line);
void	init_mlx(t_mlx *mlx, t_map *map);
void	init_line(t_point *line, t_mlx *mlx);
void	init_s_map(t_map *map);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/check_map.c                           */
/* -------------------------------------------------------------------------- */
bool	check_chars(char *s);
bool	check_format(char *file_name);
bool	check_arg(char *arg, t_map *map);
int	get_int(char *buffer, int *i);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/fdf_utils.c                           */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/draw_map.c                            */
/* -------------------------------------------------------------------------- */
bool	draw_map_x(t_map *map, t_mlx *mlx, t_point *line);
bool	draw_map_y(t_map *map, t_mlx *mlx, t_point *line);

/* -------------------------------------------------------------------------- */
/*                         FILE = src/get_next_line.c                         */
/* -------------------------------------------------------------------------- */
char	*ft_fill_line(char *buffer, int fd, char **remain);
char	*clean_remain(char *remain);
char	*get_next_line(int fd);

/* -------------------------------------------------------------------------- */
/*                            FILE = src/square.c                             */
/* -------------------------------------------------------------------------- */
int	put_square(void	*mlx, void *win, int middle_x, int middle_y, int color, int size);
int	ft_atoi(const char *str);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/draw_line.c                           */
/* -------------------------------------------------------------------------- */
void	draw_line(t_mlx *mlx, t_point *seg, int couleur, t_map *map);

/* -------------------------------------------------------------------------- */
/*                            FILE = src/parsing.c                            */
/* -------------------------------------------------------------------------- */
void	get_lines(char *buffer, t_map *map);
int	get_size(char *buffer);
bool	check_size(char *buffer, t_map *map);
char	*parsing(char *arg, t_map *map);
bool	init_map(char *buffer, t_map *map);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/free.c                              */
/* -------------------------------------------------------------------------- */
void free_all(char *buffer, t_map *map);


#endif
