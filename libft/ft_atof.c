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

#include "libft.h"

double	ft_atof(const char *nptr)
{
	double	nb;
	double	fraction;
	int	flag;
	int	mi;

	nb = 0.0;
	flag = 0;
	fraction = 0.1;
	mi = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mi *= -1;
		nptr++;
		flag++;
	}
	if (flag > 1)
		return (nb);
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
	return (nb * mi);
}
