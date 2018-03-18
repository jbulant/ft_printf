#include "ft_printf.h"

int	parse_oct(t_printf_data *data)
{
	int		oct;
	char	*str;

	data->current_arg.delim |= DELIM_OCTAL;
	oct = va_arg(data->args, int);
	str = ft_static_itoa_base(oct, 8);
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
