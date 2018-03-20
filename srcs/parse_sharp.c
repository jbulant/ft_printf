#include "ft_printf.h"

void		parse_sharp(t_printf_data *data)
{
	static const char	*letters[3] = {"0","0x","0X"};
	size_t				i;

	if (!(data->current_arg.spec & SPEC_HASH))
		return ;
	i = (letters[data->current_arg.delim] == DELIM_OCTAL) ? 1 : 2;
	data->ret_value += ft_big_strncat(&data->str
						, letters[data->current_arg.delim]
						, i);
}