#include "ft_printf.h"

int	ft_str_toupper(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (0);
}

int	parse_hex(t_printf_data *data)
{
	int		hex;
	char	*str;

	data->current_flags |= DELIM_HEX;
	hex = va_arg(data->args, int);
	str = ft_static_itoa_base(hex, 16);
	if (!(data->format_string[data->format_index] & 32))
		ft_str_toupper(str);
	ft_strcat(data->str->buffer + data->str->size, str);
	data->str->size += ft_strlen(str);
	data->current_flags = 0;
	data->format_index++;
	return ((data->status = COPYING));
}
