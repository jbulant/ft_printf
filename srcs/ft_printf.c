#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	static t_printf_data	data = {0};
	static int				(*action[3])(t_printf_data*) = {NULL,
															ft_printf_copy,
															ft_printf_analyze};

	(void)action;
	va_start(data.args, format);
	if (!data.root_str)
		data.root_str = ft_create_str();
	data.str = data.root_str;
	data.format_string = format;
	data.format_index = 0;
	if (!data.format_string)
	{
		data.ret_value = -1;
		data.status = FINISH;
	}
	else
		data.status = COPYING;
	while(TREATING(data.status))
	{
		action[data.status](&data);
		//treat data
	}
	// finishing + write + clean
	va_end(data.args);
	ft_printf_close(&data);
	return (data.ret_value);
}
