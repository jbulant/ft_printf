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

char			*ft_static_ultoa_base(uint64_t nb, int base)
{
	static char		charset[17] = "0123456789abcdef";
	static char		str[67];
	size_t			len;

	len = nblen(nb, base) + 1;
	str[len] = '\0';
	str[--len] = charset[nb % base];
	while ((nb /= base))
		str[--len] = charset[nb % base];
	return (str);
}
