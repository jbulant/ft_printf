#include <stdint.h>
#include "libft.h"

static size_t	nblen(uint64_t n)
{
	size_t len;

	len = 0;
	while ((n /= 10) > 0)
		len++;
	return (len);
}

char			*ft_static_ultoa(uint64_t nb)
{
	static char		str[24];
	size_t			len;

	len = nblen(nb) + 1;
	str[len] = '\0';
	str[--len] = (nb % 10) + '0';
	while ((nb /= 10))
		str[--len] = (nb % 10) + '0';
	return (str);
}
