/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/05/11 03:13:02 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "struct.h"
# include "includes.h"
# include "../lib/minilibx-linux/mlx.h"

/* -------------------------------------------------------------------------- */
/*                             FILE = src/hooks.c                             */
/* -------------------------------------------------------------------------- */
void	init_hooks(t_mlx *mlx);
int find_start_map(t_map *map, t_point *line);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/get_color.c                           */
/* -------------------------------------------------------------------------- */
int	strhexlen(char *buffer);
bool	ishexdigit(char c);
int	ft_atohex(char *buffer);

/* -------------------------------------------------------------------------- */
/*                      FILE = src/get_next_line_utils.c                      */
/* -------------------------------------------------------------------------- */
char	*ft_strndup(char *str);
int	check_buff(char *buffer, char c);
char	*ft_strjoin(char *remain, char *buffer);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/main.c                              */
/* -------------------------------------------------------------------------- */
int	get_biggest_len(t_data *data);
void	init_mlx(t_data *data);
void	init_line(t_point *line, t_data *data);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/check_map.c                           */
/* -------------------------------------------------------------------------- */
bool	check_format(char *file_name);
char	*get_map(char *arg);
int	ft_atoi(char *buffer, int *index);
bool	init_map(char *file_name, t_map	***map, t_data *data);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/fdf_utils.c                           */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/draw_map.c                            */
/* -------------------------------------------------------------------------- */
bool	draw_map_x(t_map ***map, t_data *data, t_point *line);
bool	draw_map_y(t_map ***map, t_data *data, t_point *line);

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

/* -------------------------------------------------------------------------- */
/*                           FILE = src/draw_line.c                           */
/* -------------------------------------------------------------------------- */
void	draw_line(t_data *data, t_point *seg, int couleur);

/* -------------------------------------------------------------------------- */
/*                            FILE = src/parsing.c                            */
/* -------------------------------------------------------------------------- */
int	get_line_len(char *str, int i);
bool	isprintable(char c);
int	get_lines(char *str);
void	free_map(t_map ***map, int i);
bool	parsing_map(char *buffer, t_map ***map, t_data *data);


#endif
