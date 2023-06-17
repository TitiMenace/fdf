#include "struct.h"
#include "fdf.h"
#include "includes.h"



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
