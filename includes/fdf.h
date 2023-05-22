/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:21:11 by tschecro          #+#    #+#             */
/*   Updated: 2023/05/22 20:48:49 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "struct.h"
# include "includes.h"
# include "../lib/minilibx-linux/mlx.h"

/* -------------------------------------------------------------------------- */
/*                           FILE = src_bonus/mlx.c                           */
/* -------------------------------------------------------------------------- */
void	img_init(t_data	*data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* -------------------------------------------------------------------------- */
/*                          FILE = src_bonus/hooks.c                          */
/* -------------------------------------------------------------------------- */
int	destroy(t_data *data);
int	cross_button(t_data *data);
void	init_hooks(t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/get_color.c                        */
/* -------------------------------------------------------------------------- */
int	strhexlen(char *buffer);
bool	ishexdigit(char c);
int	ft_atohex(char *buffer);

/* -------------------------------------------------------------------------- */
/*                   FILE = src_bonus/get_next_line_utils.c                   */
/* -------------------------------------------------------------------------- */
char	*ft_strndup(char *str);
int	check_buff(char *buffer, char c);
char	*ft_strjoin(char *remain, char *buffer);

/* -------------------------------------------------------------------------- */
/*                          FILE = src_bonus/main.c                           */
/* -------------------------------------------------------------------------- */
int	get_biggest_len(t_data *data);
void	init_mlx(t_data *data);
void	init_offset(t_data *data);
void	init_line(t_point *line, t_data *data);
void	rendering(t_data *data);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/check_map.c                        */
/* -------------------------------------------------------------------------- */
bool	check_format(char *file_name);
char	*get_map(char *arg);
int	ft_atoi(char *buffer, int *index);
bool	init_map(char *file_name, t_map	***map, t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/fdf_utils.c                        */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/draw_map.c                         */
/* -------------------------------------------------------------------------- */
void	projections(t_point *line, t_data *data, t_rot *r1, t_rot *r2);
void	init_rot(t_rot *rotate, float x, float y, float z, t_point *line);
bool	draw_map_x(t_map ***map, t_data *data, t_point *line);
bool	draw_map_y(t_map ***map, t_data *data, t_point *line);

/* -------------------------------------------------------------------------- */
/*                      FILE = src_bonus/get_next_line.c                      */
/* -------------------------------------------------------------------------- */
char	*ft_fill_line(char *buffer, int fd, char **remain);
char	*clean_remain(char *remain);
char	*get_next_line(int fd);

/* -------------------------------------------------------------------------- */
/*                         FILE = src_bonus/rotates.c                         */
/* -------------------------------------------------------------------------- */
void	init_angle(t_data *data);
void	init_rotations(t_rot *rotation, t_data *data);
void	rotate_z(t_rot *rot, t_data *data);
void	rotate_y(t_rot *rot, t_data *data);
void rotate_x(t_rot *rot, t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/isometric.c                        */
/* -------------------------------------------------------------------------- */
float	x_projection(t_data *data, float x, float y);
float	y_projection(t_data *data, float x, float y, float z);

/* -------------------------------------------------------------------------- */
/*                         FILE = src_bonus/square.c                          */
/* -------------------------------------------------------------------------- */
int	put_square(void	*mlx, void *win, int middle_x, int middle_y, int color, int size);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/draw_line.c                        */
/* -------------------------------------------------------------------------- */
void	draw_line(t_data *data, t_point *seg, int couleur);

/* -------------------------------------------------------------------------- */
/*                         FILE = src_bonus/parsing.c                         */
/* -------------------------------------------------------------------------- */
int	get_line_len(char *str, int i);
bool	isprintable(char c);
int	get_lines(char *str);
void	free_map(t_map ***map, int i);
bool	parsing_map(char *buffer, t_map ***map, t_data *data);


#endif
