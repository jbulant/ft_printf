#include "ft_printf.h"

int		parse_unsigned_type(t_printf_data *data)
{
	uint64_t	integer;
	char	*str;

	data->current_arg.delim |= DELIM_UNSIGNED;
	integer = va_arg(data->args, uint64_t); //sera modifie par les modifiers
	str = ft_static_ultoa((uint64_t)integer);
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
