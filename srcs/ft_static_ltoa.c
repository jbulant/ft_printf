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

char			*ft_static_ltoa(int64_t n)
{
	static char		str[24];
	uint64_t		nb;
	size_t			len;

	nb = n < 0 ? (uint64_t)-n : (uint64_t)n;
	len = nblen(nb) + ((n >= 0) ? 1 : 2);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	str[--len] = (nb % 10) + '0';
	while ((nb /= 10))
		str[--len] = (nb % 10) + '0';
	return (str);
}
