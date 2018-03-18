#include "ft_printf.h"

int		parse_char_type(t_printf_data *data)
{
	char	c;

	c = (char)va_arg(data->args, int);
	data->current_arg.delim |= DELIM_CHAR;
	data->ret_value += ft_big_strset(&data->str, c, 1);
	data->format_index++;
	data->current_arg = ft_new_printf_arg();
	return ((data->status = COPYING));
}
