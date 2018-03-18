#include "ft_printf.h"



int		parse_int_type(t_printf_data *data)
{
	int		integer;
	char	*mod;

	data->current_arg.delim |= DELIM_INT;
	//ft_cast()
	// data->current_arg.value = (uint64_t)va_arg(data->args, int);
	integer = va_arg(data->args, int);
	mod = ft_static_itoa(integer);
	data->ret_value += ft_big_strncat(&data->str, mod, ft_strlen(mod));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
