#include "ft_printf.h"

int		parse_str_type(t_printf_data *data, t_flags *flag)
{
	char	*str;

	str = va_arg(data->args, char *);
	*flag |= DELIM_STR;
	ft_strcat(data->str->buffer + data->str->size, str);
	data->str->size += ft_strlen(str);
	data->format_index++;
	*flag = 0;
	return ((data->status = COPYING));
}
