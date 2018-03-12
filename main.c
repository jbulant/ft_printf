#include <stdio.h>
#include "./includes/ft_printf.h"
//#include "libft.h"

int			main(int ac, char **av)
{
	if (ac == 1)
		return (0);
//	ft_putendl("coucou");
	ft_printf("%X, %s, %x\n", atoi(av[1]), av[1], atoi(av[1]));
	return (0);
}
