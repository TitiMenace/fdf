/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:08:14 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 16:08:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "test_int.h"

//Functions from file : parsing.c
int		get_line_len(char *str, int i);

bool	isprintable(char c);

int		get_lines(char *str);

void	free_map(t_map ***map, int i);

bool	parsing_map(char *buffer, t_map ***map, t_data *data);

//Functions from file : draw_line.c
void	draw_line(t_data *data, t_point *seg, int couleur);

//Functions from file : square.c
int		put_square(void	*mlx, void *win, int middle_x, int middle_y, \
int color, int size);

//Functions from file : isometric.c
float	get_focal_lenght(float x, float y, float z);

float	x_projection(t_data *data, float x, float z);

float	y_projection(t_data *data, float y, float z);

//Functions from file : rotates.c
void	init_angle(t_data *data);

void	init_special_rotations(t_rot *rotation, t_data *data);

void	init_rotations(t_rot *rotation, t_data *data);

void	rotate_z(t_rot *rot, t_data *data);

void	rotate_y(t_rot *rot, t_data *data);

//Functions from file : get_next_line.c
char	*get_next_line(int fd);

//Functions from file : draw_map.c
void	projections(t_point *line, t_data *data, t_rot *r1, t_rot *r2);

void	init_rot(t_rot *rotate, float x, float y, float z, int color);

void	init_origin(t_rot *r1, t_rot *r2);

void	draw(t_rot *r1, t_rot *r2, t_data *data,  t_point *line, \
int color);

bool	draw_adjacent(int i, t_map ***map, t_data *data, t_point *line);

bool	draw_map(t_map ***map, t_data *data, t_point *line);

//Functions from file : fdf_utils.c
int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2);

//Functions from file : check_map.c
bool	check_format(char *file_name);

char	*get_map(char *arg);

int		ft_atoi(char *buffer, int *index);

bool	init_map(char *file_name, t_map	***map, t_data *data);

//Functions from file : initialization.c
void	init_cinematic(t_data *data);

void	init_color(t_data *data);

void	init_projections(t_data *data);

void	init_offset(t_data *data);

void	init_line(t_point *line, t_data *data);

//Functions from file : main.c
void	init_mlx(t_data *data);

void	rendering(t_data *data);

void	initializations(t_data *data);

//Functions from file : get_next_line_utils.c
char	*ft_strndup(char *str);

int		check_buff(char *buffer, char c);

//Functions from file : get_color.c
int		strhexlen(char *buffer);

bool	ishexdigit(char c);

int		ft_atohex(char *buffer);

//Functions from file : color.c
float	max(float a, float b);

float	min(float a, float b);

int		argb_to_int(int a, int r, int g, int b);

int		get_point_color(t_data *data, float z_origin, float z_rotated);

int		get_rotated_color(t_data *data, float z_origin, \
float z_rotated);

int		get_red(t_data *data, float z_origin, float z_rotated);

//Functions from file : hooks.c
int		destroy(t_data *data);

int		cross_button(t_data *data);

void	init_hooks(t_data *data);

//Functions from file : mlx.c
void	ft_memset(void *ptr, int value, size_t count);

void	img_init(t_data	*data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif