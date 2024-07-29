#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_data data;
	if (argc == 2)
	{
		if (!ft_memcmp("Mandelbrot", argv[1], ft_strlen("Mandelbrot")))
			init_mlx(&data);
	}
	if (argc == 4)
	{
		data.juli_cre = ft_atof(argv[2]);
		data.juli_cim = ft_atof(argv[3]);
		if (!ft_memcmp("Julia", argv[1], ft_strlen("Julia")))
			init_mlx2(&data);
	}
	ft_printf("Error\n");
	return (0);
}