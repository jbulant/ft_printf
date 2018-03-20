#include "ft_printf.h"

t_printf_arg	ft_new_printf_arg(void)
{
	t_printf_arg arg;

	ft_bzero((void*)&arg, sizeof(t_printf_arg));
	return (arg);
}

static void		init_printf(t_printf_data *data)
{
	data->current_arg = ft_new_printf_arg();
	data->str.size = 0;
	data->format_index = 0;
	data->max_copy = 0;
	data->ret_value = 0;
	if (!data->format_string)
	{
		data->ret_value = -1;
		data->status = FINISH;
	}
	else
		data->status = COPYING;
}

int				ft_printf(const char *format, ...)
{
	static t_printf_data	data;
	static int				(*action[3])(t_printf_data*) = {NULL,
															ft_printf_copy,
															ft_printf_analyze};

	va_start(data.args, format);
	data.format_string = format;
	init_printf(&data);
	while(TREATING(data.status))
		action[data.status](&data);
	va_end(data.args);
	ft_printf_close(&data);
	return (data.ret_value);
}
