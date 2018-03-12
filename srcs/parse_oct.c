#include "ft_printf.h"

int	parse_oct(t_printf_data *data, t_flags *flag)
{
	int		oct;
	char	*str;

	*flag |= DELIM_OCTAL;
	oct = va_arg(data->args, int);
	str = ft_static_itoa_base(oct, 8);
	ft_strcat(data->str->buffer + data->str->size, str);
	data->str->size += ft_strlen(str);
	*flag = 0;
	data->format_index++;
	return ((data->status = COPYING));
}
