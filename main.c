#include <stdio.h>
#include "./includes/ft_printf.h"
//#include "libft.h"
#include <limits.h>
#include <locale.h>

int			main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	long long int i;
	if (ac == 1)
		return (0);
	i = LLONG_MAX;
//	printf("THEM===\n");
//	printf("%d\n", printf("%p\n", av[1]));
//	printf("%d\n", printf("%hhd\n", i));
//	printf("OUR ===\n");
//	ft_printf("%d\n", ft_printf("%p\n", av[1]));

//	ft_printf("%d\n", ft_printf("%hdtruc\n", 0x22394));
	ft_printf("%h    = %h\n");
	ft_printf("%hl   = %hl\n");
	ft_printf("%lh   = %lh\n");
	ft_printf("%hhlhd = %hd\n", 5, 53);
//	printf("%llu \n", LLONG_MAX + 2);
	
	return (0);
}
