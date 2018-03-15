#include "ft_printf.h"

int		parse_unsigned_type(t_printf_data *data)
{
	uint64_t	integer;
	char	*str;

	data->current_flags |= DELIM_UNSIGNED;
	integer = va_arg(data->args, uint64_t); //sera modifie par les modifiers
	str = ft_static_ultoa((uint64_t)integer);
	ft_strcat(data->str->buffer + data->str->size, str);
	data->str->size += ft_strlen(str);
	data->current_flags = 0;
	data->format_index++;
	return ((data->status = COPYING));
}
