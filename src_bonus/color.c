#include "struct.h"
#include "fdf.h"
#include "includes.h"


unsigned int get_interpolated_color(t_data *data, unsigned int start_color, unsigned int end_color, double t)
{
	unsigned char	start_r;
	unsigned char 	start_g;
	unsigned char	start_b;

	unsigned char 	end_r;
	unsigned char	end_g;
	unsigned char	end_b;

	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	
	if (data->z_min == data->z_max)
		return (0x00FF0000);

	start_r = (start_color >> 16) & 0xFF;
	start_g = (start_color >> 8) & 0xFF;
	start_b = start_color & 0xFF;

	end_r = (end_color >> 16) & 0xFF;
	end_g = (end_color >> 8) & 0xFF;
	end_b = end_color & 0xFF;

	r = (float)(start_r + (end_r - start_r) * t);
	g = (float)(start_g + (end_g - start_g) * t);
	b = (float)(start_b + (end_b - start_b) * t);

	return ((r << 16) | (g << 8) | b);
}



float	max(float a, float b)
{
	return (a < b ? b : a);
}

float	min(float a, float b)
{
	return (a < b ? a : b);
}

int	argb_to_int(int a, int r, int g, int b)
{
	return ((a << 24) + (r << 16) + (g << 8) + b);
}


int	get_point_color(t_data *data, float z_origin, float z_rotated)
{	
	float	z;	
	(void)data;
	(void)z_rotated;
	
	z = z_origin;
	z += 20;
	z = max(z, 0.);
	z = min(z, 40.);
	z /= 40.;
	z *= 255;
	return (argb_to_int(0, z, 0, 255 - z));
}

int	get_rotated_color(t_data *data, float z_origin, float z_rotated)
{	
	float	z;
	(void)data;
	(void)z_origin;
	
	z = z_rotated;
	z += 20;
	z = max(z, 0.);
	z = min(z, 40.);
	z /= 40.;
	z *= 255;
	return (argb_to_int(0, z, 0, 255 - z));
}

int	get_red(t_data *data, float z_origin, float z_rotated)
{
	(void)data;
	(void)z_origin;
	(void)z_rotated;
	return (0x00ff0000);	
}
