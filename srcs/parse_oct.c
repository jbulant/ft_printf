#include "ft_printf.h"

int	parse_oct(t_printf_data *data)
{
	int		oct;
	char	*str;

	data->current_flags |= DELIM_OCTAL;
	oct = va_arg(data->args, int);
	str = ft_static_itoa_base(oct, 8);
	ft_strcat(data->str->buffer + data->str->size, str);
	data->str->size += ft_strlen(str);
	data->current_flags = 0;
	data->format_index++;
	return ((data->status = COPYING));
}
