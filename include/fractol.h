# ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/gnl_check_bonus/get_next_line.h"
# include "../libft/gnl_check_bonus/get_next_line_bonus.h"
# include "../ft_printf/libftprintf.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#  define XLEN 860
#  define YLEN 540

typedef struct  s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

typedef struct  s_mlx
{
    void *mlx;
    void *win;
}   t_mlx;

typedef struct  s_complex
{
    double left;
    double xlen;
    double top;
    double ylen;
}   t_complex;

typedef struct  s_dot
{
    double real;
    double im;
}   t_dot;

//mt_mlx.c
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void init_mlx(t_mlx *mlx, t_data *data);
//mandelbrot .c
void init_complex(t_complex *val);
int is_convergence(double a, double b, t_complex *val);
void mandelbort(t_mlx *mlx, t_data *data);

# endif