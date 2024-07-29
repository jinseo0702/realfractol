#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mouse_hook(int mouse, int x, int y, t_data *data) 
{
	zoom(data, mouse, x, y);
	mandelbort(data);
	// ft_printf("mouse hook and I use mouse hook %d %d %d %d\n", mouse, (int)data->left, x, y);
	return (mouse);
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		ft_printf("Good bye my friends\n");
		exit (0);
	}
	// ft_printf("key hook and I use mouse hook %d %d\n", keycode, (int)data->left);
	return (1);
}

int ftclose(t_data *data)
{
	ft_printf("Good bye my friends\n");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void init_mlx(t_data *data)
{
	init_complex(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, XLEN, YLEN, "Hello fractol");
	data->img = mlx_new_image(data->mlx, XLEN, YLEN);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	mandelbort(data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, ftclose, data);

	mlx_loop(data->mlx);
}