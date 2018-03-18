#include "ft_printf.h"

int		parse_unicode(t_printf_data *data)
{
	t_unicode	ucode;

	ucode.c = va_arg(data->args, wchar_t);
	data->current_arg.delim |= DELIM_UNI_CHAR;
	if ((int)ucode.c < 0)
	{
		data->status = FINISH;
		data->ret_value = -1;
		return (-1);
	}
	ucode = convert_unicode(ucode);
	data->ret_value += ft_big_strncat(&data->str, (char*)&ucode.c, ucode.size);
	data->format_index++;
	data->current_arg = ft_new_printf_arg();
	return ((data->status = COPYING));
}
