int	put_square(void	*mlx, void *win, int middle_x, int middle_y, int color, int size)
{
	int	count;

	count = 0;
	middle_x = middle_x - (size / 2);
	while(count < size / 2)
	{
		mlx_pixel_put(mlx, win, middle_x, middle_y, color);
		middle_y++;
		count++;
	}
	count = 0;
	while (count < size)
	{
		mlx_pixel_put(mlx, win, middle_x, middle_y, color);
		middle_x++;
		count++;
	}
	count = 0;
	while (count < size)
	{
		mlx_pixel_put(mlx, win, middle_x, middle_y, color);
		middle_y--;
		count++;
	}
	count = 0;
	while (count < size)
	{
		mlx_pixel_put(mlx, win, middle_x, middle_y, color);
		middle_x--;
		count++;
	}
	count = 0;
	while (count < size / 2)
	{
		mlx_pixel_put(mlx, win, middle_x, middle_y, color);
		middle_y++;
		count++;
	}
	return (1);
}
