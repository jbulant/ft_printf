#include <stdint.h>
#include "libft.h"

static size_t	nblen(uint64_t n, int base)
{
	size_t len;

	len = 0;
	while ((n /= base) > 0)
		len++;
	return (len);
}

char			*ft_static_ltoa_base(int64_t n, int base)
{
	static char		charset[17] = "0123456789abcdef";
	static char		str[67];
	uint64_t		nb;
	size_t			len;

	nb = n < 0 ? (uint64_t)-n : (uint64_t)n;
	len = nblen(nb, base) + ((n >= 0 || base != 10) ? 1 : 2);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	str[--len] = charset[nb % base];
	while ((nb /= base))
		str[--len] = charset[nb % base];
	return (str);
}
