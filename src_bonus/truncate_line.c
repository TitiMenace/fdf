#include "fdf.h"
#include "struct.h"
#include "includes.h"


//https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect

bool	check_collide(t_point *seg, t_point *border, t_data *data)
{
	t_point	vectors;
	float	s;
	float	t;
	float	divider;

	vectors.a_x = seg->b_x - seg->a_x;
	vectors.a_y = seg->b_y - seg->a_y;
	vectors.b_x = border->b_x - border->a_x;
	vectors.b_y = border->b_y - border->a_y;
	divider =  (float)(-(long)vectors.b_x * vectors.a_y + (long)vectors.a_x * vectors.b_y);
	if (divider == 0.)
		return (false);
	s = (-vectors.a_y * ((long)seg->a_x - border->a_x) + vectors.a_x * ((long)seg->a_y - border->a_y)) / divider;
	t = (vectors.b_x * ((long)seg->a_y - border->a_y) - vectors.b_y * ((long)seg->a_x - border->a_x)) / divider;
	if (s >= 0. && s <= 1. && t >= 0. && t <= 1.)
	{
		seg->a_x += (t * vectors.a_x);
		seg->a_y += (t * vectors.a_y);
		if (seg->a_x < 0)
			seg->a_x = 0;
		if (seg->a_y < 0)
			seg->a_y = 0;
		if (seg->a_x >= data->mlx.w_w)
			seg->a_x = data->mlx.w_w - 1;
		if (seg->a_y >= data->mlx.w_h)
			seg->a_y = data->mlx.w_h - 1;
		return (true);
	}
	return (false);
}

bool is_in_screen(int x, int y, t_data *data)
{
	if (x >= 0 && x < data->mlx.w_w)
	{
		if (y >= 0 && y < data->mlx.w_h)
			return (true);
	}
	return (false);
}



bool	truncate_to_intersection(t_point *seg, t_data *data)
{
	if (seg->a_x < 0)
		if(check_collide(seg, &data->border.left_border, data))
			return (true);
	if (seg->a_x >= data->mlx.w_w)
		if(check_collide(seg, &data->border.right_border, data))
			return (true);
	if (seg->a_y < 0)
		if(check_collide(seg, &data->border.high_border, data))
			return (true);
	if (seg->a_y >= data->mlx.w_h)
		if(check_collide(seg, &data->border.bottom_border, data))
			return (true);
	return (false);
}

bool	truncate_line_origin_to_screen(t_point *seg, t_data *data)
{
	if (is_in_screen(seg->a_x, seg->a_y, data))
		return (true);
	if (!truncate_to_intersection(seg, data))
		return (false);
	return (true);
}
void caca()
{

}

bool	truncate_line(t_point *seg, t_data *data, t_bresen *helper)
{
	float tmp_x;
	float tmp_y;

	(void)helper;
	//dprintf(2, "a %d,%d b %d,%d\n", seg->a_x, seg->a_y, seg->b_x, seg->b_y);
	//if (seg->b_x == -3331048 && seg->a_x == 982 && seg->b_y == -8370098 && seg->a_y == 605)
	//	caca();
	if (!truncate_line_origin_to_screen(seg, data))
		return (false);
	
	tmp_x = seg->a_x;
	tmp_y = seg->a_y;
	seg->a_x = seg->b_x;
	seg->a_y = seg->b_y;
	seg->b_x = tmp_x;
	seg->b_y = tmp_y;
	truncate_line_origin_to_screen(seg, data);
	tmp_x = seg->a_x;
	tmp_y = seg->a_y;
	seg->a_x = seg->b_x;
	seg->a_y = seg->b_y;
	seg->b_x = tmp_x;
	seg->b_y = tmp_y;
	return (true);
}
