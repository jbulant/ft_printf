#include <stdio.h>
#include "./includes/ft_printf.h"
#include "libft.h"

int			main(int ac, char **av)
{
	if (ac == 1)
		return (0);
//	ft_putendl("coucou");
	ft_printf("%s\n", av[1]);
	return (0);
}
