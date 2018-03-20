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
	char	*str;

	if (data->format_string[data->format_index] & 32)
		data->current_arg.delim = DELIM_LHEX;
	else
		data->current_arg.delim = DELIM_UHEX;
	if (data->current_arg.spec & SPEC_MINUS)
		parse_sharp(data);
	if (data->current_arg.spec & SPEC_HASH)
		data->current_arg.total_size += 2;
	ft_casts(data);
	str = (char*)data->current_arg.content;
	if (data->current_arg.delim == DELIM_UHEX)
		ft_str_toupper(str);
	data->ret_value += ft_big_strncat(&data->str, str, ft_strlen(str));
	data->current_arg = ft_new_printf_arg();
	data->format_index++;
	return ((data->status = COPYING));
}
