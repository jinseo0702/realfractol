#include "../include/fractol.h"

void init_complex(t_data *val)
{
    val->left = -3;
    val->xlen = 6;
    val->top = 2;
    val->ylen = -4;
    val->mouse = 0;
}

void zoom(t_data *val, int mouse, int x, int y)
{
	if (mouse == WH_CLK)
		init_complex(val);
	double real = val->left + x * (val->xlen) / XLEN;
    double im = val->top + y * (val->ylen) / YLEN;
	if (mouse == WH_UP)
	{
		val->xlen /= FACTOR;
		val->ylen /= FACTOR;
	}
	else if(mouse == WH_DN)
	{
		val->xlen *= FACTOR;
		val->ylen *= FACTOR;
	}
	val->left = real - val->xlen / 2;
    val->top = im - val->ylen / 2;
}

int is_convergence(double a, double b, t_data *val)
{
    int n;
    double temp;
    t_dot c;
    t_dot z;

    z.real = 0;
    z.im = 0;
    c.real = val->left + a * (val->xlen) / XLEN;
    c.im = val->top + b * (val->ylen) / YLEN;
    n = 0;
    while ((z.real * z.real) + (z.im * z.im) < 4 && n < 2048)
    {
        temp = 2 * z.real * z.im;
        z.real = (z.real * z.real) - (z.im * z.im) + c.real;
        z.im = temp + c.im;
        n++;
    }
    return (n);
}

void mandelbort(t_data *data)
{
    double a;
    double b;
    int n;
    // int color;
    int color2;

	mlx_clear_window(data->mlx, data->win);
    a = 0;
    n = 0;
    // color = 0x0000FF;
    color2 = 0xFFFFFF;
    while (a < XLEN)
    {
        b = 0;
        while (b < YLEN)
        {
            n = is_convergence(a, b, data);
            if (n == 2048)
                my_mlx_pixel_put(data, a, b, color2);
            else
			{
				ft_printf("%d ", ft_color(n));
                my_mlx_pixel_put(data, a, b, ft_color(n));
			}
            b++;
        }
        a++;
		ft_printf("\n");
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}