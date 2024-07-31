#include "../include/fractol.h"

void print_list(void)
{
	ft_printf("Please add what is on the list \n");
	ft_printf("1. Mandelbrot \n");
	ft_printf("2. Julia -> this check complex number coordinate \n");
}

double check_julia(char *ar)
{
	char *str;
	int idx;
	static int flag;

	idx = 0;
	flag = 0;
	str = ar;
	while (str[idx])
	{
		if (str[idx] == '+' || str[idx] == '-')
			idx++;
		if (str[idx] == '.')
		{
			flag++;
			idx++;
		}
		if (flag > 1)
			print_complex();
		if (ft_isdigit(str[idx]) == 0)
			print_complex();
		idx++;
	}
	return(ft_atof_julia(str));
}

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
		data.juli_cre = check_julia(argv[2]);
		data.juli_cim = check_julia(argv[3]);
		if (!ft_memcmp("Julia", argv[1], ft_strlen("Julia")))
			init_mlx2(&data);
	}
	print_list();
	return (0);
}