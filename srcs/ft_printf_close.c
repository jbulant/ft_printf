#include "ft_printf.h"

void	ft_printf_close(t_printf_data *data)
{
	if (data->ret_value != -1)
		data->ret_value += data->str.size;
	ft_big_putstr(&data->str);
	data->current_arg = ft_new_printf_arg();
}
