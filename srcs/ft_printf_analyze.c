#include "ft_printf.h"

int			ft_printf_analyze(t_printf_data *data)
{
	static int		(*hashtab[128])(t_printf_data*) = {0};
	static t_bool	loaded = FALSE;
	int		i = -1;

	if (!loaded)
	{
	  while (++i < 128)
			hashtab[i] = parse_error;
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
		hashtab['h'] = set_mod_h;
		hashtab['l'] = set_mod_l;
		hashtab['j'] = set_mod_j;
		hashtab['z'] = set_mod_z;
		hashtab['.'] = set_precision;
		hashtab['1'] = set_width_digit;
		hashtab['2'] = set_width_digit;
		hashtab['3'] = set_width_digit;
		hashtab['4'] = set_width_digit;
		hashtab['5'] = set_width_digit;
		hashtab['6'] = set_width_digit;
		hashtab['7'] = set_width_digit;
		hashtab['8'] = set_width_digit;
		hashtab['9'] = set_width_digit;
		hashtab['*'] = set_width_wildcard;
		hashtab['-'] = set_minus_sign;
		hashtab['+'] = set_plus_sign;
		hashtab[' '] = set_space;
		loaded = TRUE;
	}
	data->format_index++;
	if (data->format_string[data->format_index] == '%')
	{
		ft_big_strset(&data->str, '%', 1);
		data->format_index++;
		data->current_arg = ft_new_printf_arg();
		data->status = COPYING;
	}
	//else if (data->format_string[data->format_index] == 'd')
	hashtab[(int)data->format_string[data->format_index]](data);
	return (0);
}
