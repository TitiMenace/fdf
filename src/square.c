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

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
