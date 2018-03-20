#include "ft_printf.h"

int		parse_unsigned_type(t_printf_data *data)
{
	char	*str;

	data->current_arg.delim = DELIM_UNSIGNED;
	ft_casts(data);
	str = (char*)data->current_arg.content;
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
