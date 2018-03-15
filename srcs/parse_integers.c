#include "ft_printf.h"



int		parse_int_type(t_printf_data *data)
{
	int		integer;
	char	*mod;
	size_t	size;

	data->current_flags |= DELIM_INT;
	//ft_cast()
	integer = va_arg(data->args, int);
	mod = ft_static_itoa(integer);
	size = ft_strlen(mod);
	ft_strcat(data->str->buffer + data->str->size, mod);
	data->str->size += size;
	data->current_flags = 0;
	data->format_index++;
	return ((data->status = COPYING));
}
