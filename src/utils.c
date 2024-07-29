#include "../include/fractol.h"

int ft_color(int n)
{
	int cnt;

	cnt = 0;
	while (cnt < 8)
	{
		if (cnt * TWOPE <= n && n < (cnt + 1) * TWOPE)
			break ;
		cnt++;
	}
	return (choose_color(cnt));
}

int choose_color(int cnt)
{
	if(cnt == 0)
		return (0xCD0000);
	else if(cnt == 1)
		return (0xCD3C3C);
	else if(cnt == 2)
		return (0xCD4646);
	else if(cnt == 3)
		return (0xCD5050);
	else if(cnt == 4)
		return (0xD25A5A);
	else if(cnt == 5)
		return (0xEB6464);
	else if(cnt == 6)
		return (0xF06E6E);
	else
		return (0xF57878);
}