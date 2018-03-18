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

	if (!(data->format_string[data->format_index] & 32))
		data->current_arg.delim |= DELIM_UHEX;
	else
		data->current_arg.delim |= DELIM_LHEX;		
	hex = va_arg(data->args, int);
	str = ft_static_itoa_base(hex, 16);
	if (!(data->current_arg.delim & DELIM_UHEX))
		ft_str_toupper(str);
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
