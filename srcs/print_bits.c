#include "ft_printf.h"

void	ft_swp(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_bits(int unicode)
{
	char	rev[4];
	int		i;

	*(int*)rev = unicode;
	ft_swp(&rev[0], &rev[3]);
	ft_swp(&rev[1], &rev[2]);
	unicode = *(int*)rev;
	i = 32;
	while(i-- > 0)
	{
		ft_putchar((unicode & (1 << (i)) ) ? '1' : '0');
		if(i % 4 == 0)
		{
			ft_putchar(' ');
			if(i % 8 == 0)
				ft_putchar(' ');
		}
	}
}

