#include "ft_printf.h"

int		parse_str_type(t_printf_data *data)
{
	char	*str;

	str = va_arg(data->args, char *);
	data->current_arg.delim |= DELIM_STR;
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->format_index++;
	data->current_arg = ft_new_printf_arg();
	return ((data->status = COPYING));
}
