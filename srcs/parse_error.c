#include "ft_printf.h"

int		parse_error(t_printf_data *data)
{
	data->ret_value += ft_big_strncat(&data->str
									, data->format_string + data->max_copy
									, data->format_index - data->max_copy);
	data->current_arg = ft_new_printf_arg();
	data->max_copy = 0;
	return ((data->status = COPYING));
}