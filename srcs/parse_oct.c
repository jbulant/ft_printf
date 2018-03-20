#include "ft_printf.h"

int	parse_oct(t_printf_data *data)
{
	char	*str;

	data->current_arg.delim = DELIM_OCTAL;
	if (data->current_arg.spec & SPEC_MINUS)
		parse_sharp(data);
	if (data->current_arg.spec & SPEC_HASH)
		data->current_arg.total_size += 1;
	ft_casts(data);
	str = (char*)data->current_arg.content;
	data->ret_value += ft_big_strncat(&data->str, str, data->current_arg.size);
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}

/*

*/