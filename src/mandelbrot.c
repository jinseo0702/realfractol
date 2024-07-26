#include "../include/fractol.h"

void init_complex(t_complex *val)
{
    val->left = -3;
    val->xlen = 6;
    val->top = 2;
    val->ylen = -4;
}

int is_convergence(double a, double b, t_complex *val)
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

void mandelbort(t_mlx *mlx, t_data *data)
{
    double a;
    double b;
    int n;
    int color;
    int color2;
    t_complex val;

    init_complex(&val);
    a = 0;
    n = 0;
    color = 0xFFFFFF;
    color2 = 0x000000;
    while (a < XLEN)
    {
        b = 0;
        while (b < YLEN)
        {
            n = is_convergence(a, b, &val);
            if (n == 2048)
                my_mlx_pixel_put(data, a, b, color2);
            else
                my_mlx_pixel_put(data, a, b, color);
            b++;
        }
        a++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, data->img, 0, 0);
}