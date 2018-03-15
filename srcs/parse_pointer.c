#include "ft_printf.h"

int		nilcase(t_printf_data *data)
{
	ft_strcat(data->str->buffer + data->str->size, "(nil)");
	data->str->size += 5;
	data->current_flags = 0;
	data->format_index++;
	return ((data->status = COPYING));
}

int		parse_pointer(t_printf_data *data)
{
	void	*ptr;
	char	*str;

	data->current_flags |= DELIM_POINTER;
	ptr = va_arg(data->args, void*);
	if (!ptr)
		return (nilcase(data));
	str = ft_static_ltoa_base((uint64_t)ptr, 16);
	ft_strcat(data->str->buffer + data->str->size, "0x");
	ft_strcat(data->str->buffer + (data->str->size += 2), str);
	data->str->size += ft_strlen(str);
	data->current_flags = 0;
	data->format_index++;
	return ((data->status = COPYING));
}
