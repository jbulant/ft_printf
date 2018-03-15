#include <stdio.h>
#include "./includes/ft_printf.h"
//#include "libft.h"
#include <limits.h>
#include <locale.h>
int			main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	if (ac == 1)
		return (0);
	printf("THEM===\n");
//	printf("%d\n", printf("%p\n", av[1]));
	printf("%d\n", printf(NULL, LLONG_MAX + 2, 0x80000000));
	printf("OUR ===\n");
//	ft_printf("%d\n", ft_printf("%p\n", av[1]));

	ft_printf("%d\n", ft_printf(NULL, LLONG_MAX + 2, 0x80000000));
//	printf("%llu \n", LLONG_MAX + 2);
	
	return (0);
}
