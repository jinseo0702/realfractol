#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void init_mlx(t_mlx *mlx, t_data *data)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, XLEN, YLEN, "Hello fractol");
    data->img = mlx_new_image(mlx->mlx, XLEN, YLEN);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    mandelbort(mlx, data);
    mlx_loop(mlx->mlx);
}

