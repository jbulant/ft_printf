#include <stdio.h>
#include "./includes/ft_printf.h"
//#include "libft.h"
#include <limits.h>
#include <locale.h>

int			main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	static const char *test[2] = {"2345", "23"};
	// unsigned long long t = ULLONG_MAX;
	size_t t = 0xfff;
	short s = 50;
	short g = 32;

	printf("%zu\n", sizeof(test[0]));
	ft_printf("%d: ", printf("le leur:  %-#*.*llxcoucou\n", s, g, t));
	ft_printf("%d: ", ft_printf("le notre: %*.*llxcoucou\n", s, g, t));
	printf("le leur:  %-*s ggg\n", s, "une chaine de characters");
	// ft_printf("le notre: %llu\n", t);
	return (0);
}
