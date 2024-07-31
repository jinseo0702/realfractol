/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <jinseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:42 by jinseo            #+#    #+#             */
/*   Updated: 2024/02/29 22:27:30 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void print_complex(void)
{
	ft_printf("plz turn in complex number\n");
	ft_printf("realnumber range is -2 <= c_re <= 2\n");
	ft_printf("imaginary range is -1 <= c_im <= 1\n");
	ft_printf("THX My friends\n");
	exit(EXIT_FAILURE);
}

int is_minus(char **nptr)
{
	int flag;
	int mi;

	mi = 1;
	flag = 0;
	if ((**nptr >= 9 && **nptr <= 13) || **nptr == 32)
		print_complex();
	while (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			mi *= -1;
		(*nptr)++;
		flag++;
	}
	if (flag > 1)
		print_complex();
	return (mi);
}

void is_inrange(double num)
{
	if (-2 <= num && num <= 2)
		return ;
	if (-1 <= num && num <= 1)
		return ;
	print_complex();
}

double	ft_atof_julia(char *nptr)
{
	double	nb;
	double	fraction;
	int	mi;

	nb = 0.0;
	fraction = 0.1;
	mi = 1;
	mi *= is_minus(&nptr);
	while (ft_isdigit(*nptr))
	{
		nb = (*nptr - 48) + (nb * 10);
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		while(ft_isdigit(*nptr))
		{
			nb += (*nptr - 48) * fraction;
			fraction *= 0.1;
			nptr++;
		}
	}
	is_inrange(nb * mi);
	return (nb * mi);
}
