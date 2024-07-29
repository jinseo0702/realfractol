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
		return (0x64CD3C);
	else if(cnt == 1)
		return (0x6ED746);
	else if(cnt == 2)
		return (0x78E150);
	else if(cnt == 3)
		return (0x82EB5A);
	else if(cnt == 4)
		return (0x8CF064);
	else if(cnt == 5)
		return (0x84FB84);
	else if(cnt == 6)
		return (0x89FB89);
	else
		return (0x8EFB8E);
}