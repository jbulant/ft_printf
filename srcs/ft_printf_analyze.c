#include "ft_printf.h"

int			ft_printf_analyze(t_printf_data *data)
{
	static int		(*hashtab[128])(t_printf_data*) = {0};
	static t_bool	loaded = FALSE;

	if (!loaded)
	{
		hashtab['d'] = parse_int_type;
		hashtab['D'] = parse_int_type;
		hashtab['i'] = parse_int_type;
		hashtab['s'] = parse_str_type;
		hashtab['o'] = parse_oct;
		hashtab['O'] = parse_oct;
		hashtab['x'] = parse_hex;
		hashtab['X'] = parse_hex;
		hashtab['p'] = parse_pointer;
		hashtab['u'] = parse_unsigned_type;
		hashtab['U'] = parse_unsigned_type;
		hashtab['c'] = parse_char_type;
		hashtab['C'] = parse_unicode;
		loaded = TRUE;
	}
	data->format_index++;
	if (data->format_string[data->format_index] == '%')
	{
		data->str->buffer[data->str->size++] = '%';
		data->format_index++;
		data->current_flags = 0;
		data->status = COPYING;
	}
	//else if (data->format_string[data->format_index] == 'd')
	hashtab[(int)data->format_string[data->format_index]](data);
	return (0);
}
