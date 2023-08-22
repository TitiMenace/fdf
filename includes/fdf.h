/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2021/10/19 15:08:54 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "struct.h"
# include "includes.h"
# include "../lib/minilibx-linux/mlx.h"

/* -------------------------------------------------------------------------- */
/*                          FILE = src_bonus/hooks.c                          */
/* -------------------------------------------------------------------------- */
int	destroy(t_data *data);
int	cross_button(t_data *data);
void	init_hooks(t_data *data);

/* -------------------------------------------------------------------------- */
/*                   FILE = src_bonus/get_next_line_utils.c                   */
/* -------------------------------------------------------------------------- */
char	*ft_strndup(char *str);
int	check_buff(char *buffer, char c);
char	*ft_strjoin(char *remain, char *buffer);

/* -------------------------------------------------------------------------- */
/*                           FILE = src_bonus/mlx.c                           */
/* -------------------------------------------------------------------------- */
void	ft_memset(void *ptr, int value, size_t count);
void	img_init(t_data	*data);
int	color_from_alpha(unsigned int old_color, unsigned int new_color, float alpha);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* -------------------------------------------------------------------------- */
/*                     FILE = src_bonus/cinematic_hooks.c                     */
/* -------------------------------------------------------------------------- */
void	set_mods_hooks(t_data *data, int zazou);
void	set_movements_hooks(t_data *data, int zazou);
void	set_cinematics_hooks(t_data *data, int zazou);
void	set_angles_hooks(t_data *data, int zazou);

/* -------------------------------------------------------------------------- */
/*                      FILE = src_bonus/rotates_utils.c                      */
/* -------------------------------------------------------------------------- */
void	init_angle(t_data *data);
void	init_special_rotations(t_rot *rotation, t_data *data);
void	init_rotations(t_rot *rotation, t_data *data);

/* -------------------------------------------------------------------------- */
/*                          FILE = src_bonus/color.c                          */
/* -------------------------------------------------------------------------- */
unsigned int	get_interpolated_color(t_data *data, unsigned int start_color, unsigned int end_color, double t);
float	max(float a, float b);
float	min(float a, float b);
int	argb_to_int(int a, int r, int g, int b);
int	get_point_color(t_data *data, float z_origin, float z_rotated);

/* -------------------------------------------------------------------------- */
/*                      FILE = src_bonus/colors_hooks.c                       */
/* -------------------------------------------------------------------------- */
void	set_alpha_value_hooks(t_data *data, int zazou);
void	set_colors_hooks(t_data *data, int zazou);

/* -------------------------------------------------------------------------- */
/*                      FILE = src_bonus/parsing_utils.c                      */
/* -------------------------------------------------------------------------- */

bool	parsing_malloc(int *len, int *y, t_map ***map, t_data *data);
void	set_z_range(t_data *data, t_map ***map, int y, int x);
void	get_line_len_utils(char *str, int *i, int *count);
void	get_map_color_hex(char *buffer, int *index, int *hex_color);
bool	map_allocation(t_data *data, char *buffer, t_map ***map);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/draw_line.c                        */
/* -------------------------------------------------------------------------- */
void	draw_line(t_data *data, t_point *seg);

/* -------------------------------------------------------------------------- */
/*                      FILE = src_bonus/truncate_line.c                      */
/* -------------------------------------------------------------------------- */
bool	check_collide(t_point *seg, t_point *border, t_data *data);
bool is_in_screen(int x, int y, t_data *data);
bool	truncate_to_intersection(t_point *seg, t_data *data);
bool	truncate_line_origin_to_screen(t_point *seg, t_data *data);
bool	truncate_line(t_point *seg, t_data *data);

/* -------------------------------------------------------------------------- */
/*                     FILE = src_bonus/initialization.c                      */
/* -------------------------------------------------------------------------- */
void	init_cinematic(t_data *data);
void	init_color(t_data *data);
void	init_projections(t_data *data);
void	init_offset(t_data *data);
void	init_line(t_point *line, t_data *data);

/* -------------------------------------------------------------------------- */
/*                     FILE = src_bonus/draw_line_utils.c                     */
/* -------------------------------------------------------------------------- */
void	draw_line_pixel_put(t_data *data, t_point *seg, t_bresen *help);
void	last_pixel(t_data *data, t_point *seg, t_bresen *help);
void	bresenham(t_data *data, t_point *seg, t_bresen *help, t_line *utils);
void	init_bresen_color(t_bresen *help, t_point *seg, t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/draw_map.c                         */
/* -------------------------------------------------------------------------- */
void	projections(t_point *line, t_data *data, t_rot *r1, t_rot *r2);
void	init_origin(t_rot *r1, t_rot *r2);
void	draw(t_rot *r1, t_rot *r2, t_data *data, t_point *line);
bool	draw_adjacent(int i, t_map ***map, t_data *data);
bool	draw_map(t_map ***map, t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/get_color.c                        */
/* -------------------------------------------------------------------------- */
int	strhexlen(char *buffer);
bool	ishexdigit(char c);
int	ft_atohex(char *buffer);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/fdf_utils.c                        */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *ptr, size_t count);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/check_map.c                        */
/* -------------------------------------------------------------------------- */
bool	check_format(char *file_name);
char	*get_map(char *arg);
int	ft_atoi(char *buffer, int *index);
bool	init_map(char *file_name, t_map	***map, t_data *data);

/* -------------------------------------------------------------------------- */
/*                         FILE = src_bonus/rotates.c                         */
/* -------------------------------------------------------------------------- */
void	rotate_z(t_rot *rot, t_data *data);
void	rotate_y(t_rot *rot, t_data *data);
void	rotate_x(t_rot *rot, t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/mlx_utils.c                        */
/* -------------------------------------------------------------------------- */
void	no_alpha_rendering(t_data *data);

/* -------------------------------------------------------------------------- */
/*                       FILE = src_bonus/draw_helper.c                       */
/* -------------------------------------------------------------------------- */
void	right_line_drawing(t_data *data, t_map ***map, int i, int j);
bool	down_line_drawing(t_data *data, t_map ***map, int i, int j);
void	regular_drawing(t_data *data, t_map ***map, int i, int j);
bool	drawing(t_data *data, t_map ***map, int i, int j);

/* -------------------------------------------------------------------------- */
/*                        FILE = src_bonus/isometric.c                        */
/* -------------------------------------------------------------------------- */
float	get_focal_lenght(float x, float y, float z);
float	x_projection(t_data *data, float x, float z);
float	y_projection(t_data *data, float y, float z);

/* -------------------------------------------------------------------------- */
/*                      FILE = src_bonus/get_next_line.c                      */
/* -------------------------------------------------------------------------- */
char	*ft_fill_line(char *buffer, int fd, char **remain);
char	*clean_remain(char *remain);
char	*get_next_line(int fd);

/* -------------------------------------------------------------------------- */
/*                     FILE = src_bonus/draw_map_utils.c                      */
/* -------------------------------------------------------------------------- */
void	set_init_rot_helper(t_data *data, float x, float y, float z);
void	set_origin_point(t_data *data, t_map ***map, int i, int j);
void	init_rot(t_rot *rotate, t_init_r ro, int color);

/* -------------------------------------------------------------------------- */
/*                          FILE = src_bonus/main.c                           */
/* -------------------------------------------------------------------------- */
bool	init_screen_border(t_data *data);
bool	init_mlx(t_data *data);
void	rendering(t_data *data);
bool	initializations(t_data *data);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                         FILE = src_bonus/parsing.c                         */
/* -------------------------------------------------------------------------- */
int	get_line_len(char *str, int i);
bool	isprintable(char c);
int	get_lines(char *str);
void	free_map(t_map ***map, int i);
bool	parsing_map(char *buffer, t_map ***map, t_data *data);

/* -------------------------------------------------------------------------- */
/*                         FILE = src_bonus/check_collide_utils.c             */
/* -------------------------------------------------------------------------- */

void	get_new_points(t_point *seg, t_point *vectors, t_data *data, float *t);

#endif
