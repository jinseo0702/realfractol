#include "../include/fractol.h"

int is_convergence_2(double a, double b, t_data *val)
{
    int n;
    double temp;
    t_dot z;

    z.real = val->left + a * (val->xlen) / XLEN;
    z.im = val->top + b * (val->ylen) / YLEN;
    n = 0;
    while ((z.real * z.real) + (z.im * z.im) < 4 && n < MAX)
    {
        temp = 2 * z.real * z.im;
        z.real = (z.real * z.real) - (z.im * z.im) + val->juli_cre;
        z.im = temp + val->juli_cim;
        n++;
    }
    return (n);
}

void julia(t_data *data)
{
    double a;
    double b;
    int n;
    int color2;

	mlx_clear_window(data->mlx, data->win);
    a = 0;
    n = 0;
    color2 = 0xFFFFFF;
    while (a < XLEN)
    {
        b = 0;
        while (b < YLEN)
        {
            n = is_convergence_2(a, b, data);
            if (n == MAX)
                my_mlx_pixel_put(data, a, b, color2);
            else
			{
                my_mlx_pixel_put(data, a, b, ft_color(n));
			}
            b++;
        }
        a++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	mouse_hook2(int mouse, int x, int y, t_data *data)
{
	zoom(data, mouse, x, y);
	julia(data);
	// ft_printf("mouse hook and I use mouse hook %d %d %d %d\n", mouse, (int)data->left, x, y);
	return (mouse);
}

void init_mlx2(t_data *data)
{
	init_complex(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, XLEN, YLEN, "Hello fractol");
	data->img = mlx_new_image(data->mlx, XLEN, YLEN);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	julia(data);
	mlx_mouse_hook(data->win, mouse_hook2, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, ftclose, data);

	mlx_loop(data->mlx);
}