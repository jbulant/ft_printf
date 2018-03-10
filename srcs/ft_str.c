
#include "ft_printf.h"

t_str	*ft_create_str(void)
{
	t_str *ret;

	if (!(ret = (t_str *)malloc(sizeof(t_str))))
		return (NULL);
	ret->next = NULL;
	ret->size = 0;
	return (ret);
}
