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
#  define WH_UP 4
#  define WH_DN 5
#  define WH_CLK 2
#  define ESC 65307
#  define ON_DESTROY 17
#  define TWOPE 256
// #  define C_REAL -0.5
// #  define C_IM 0
#  define FACTOR 1.1

typedef struct  s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	double left;
	double xlen;
	double top;
	double ylen;
	int mouse;
	void *mlx;
	void *win;
}	t_data;


// typedef struct  s_complex
// {
//     double left;
//     double xlen;
//     double top;
//     double ylen;
// 	int mouse;
// }   t_complex;

// typedef struct  s_mlx
// {
//     void *mlx;
//     void *win;
// }   t_mlx;

typedef struct  s_dot
{
    double real;
    double im;
}   t_dot;

//mt_mlx.c
// int	mouse_hook(int mouse);
int	mouse_hook(int mouse, int x, int y, t_data *data) ;
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int key_hook(int keycode, t_data *data);
int ftclose(t_data *data);
// void init_mlx(t_mlx *mlx, t_data *data);
void init_mlx(t_data *data);
//mandelbrot .c
void init_complex(t_data *val);
void mandelbort(t_data *data);
int is_convergence(double a, double b, t_data *val);
void zoom(t_data *val, int mouse, int x, int y);
//utils.c
int ft_color(int n);
int choose_color(int cnt);

# endif