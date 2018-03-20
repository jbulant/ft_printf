#include "ft_printf.h"

int		nilcase(t_printf_data *data)
{
	data->ret_value += ft_big_strncat(&data->str, "(null)", 6);
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}

int		parse_pointer(t_printf_data *data)
{
	void	*ptr;
	char	*str;

	data->current_arg.delim |= DELIM_POINTER;
	ptr = va_arg(data->args, void*);
	if (!ptr)
		return (nilcase(data));
	str = ft_static_ltoa_base((uint64_t)ptr, 16);
	data->ret_value += ft_big_strncat(&data->str, "0x", 2);
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
