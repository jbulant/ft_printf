#include "ft_printf.h"

int		parse_char_type(t_printf_data *data)
{
	char	c;

	c = (char)va_arg(data->args, int);
	data->current_flags |= DELIM_CHAR;
	data->str->buffer[data->str->size++] = c;
	data->format_index++;
	data->current_flags = 0;
	return ((data->status = COPYING));
}
