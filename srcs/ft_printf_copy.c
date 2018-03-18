
#include "ft_printf.h"

int	ft_printf_copy(t_printf_data *data)
{
	check_status(data);
	data->ret_value += ft_big_strncat(&data->str
									, data->format_string + data->format_index
									, data->max_copy);
	data->format_index += data->max_copy;
	data->max_copy = data->format_index;
	return (0);
}
