
#include "ft_printf.h"

int	ft_printf_copy(t_printf_data *data)
{
	check_status(data);
	if(data->max_copy + data->str->size >= STR_BUFFSIZE)
	{
		data->str->next = ft_create_str();
		data->str = data->str->next;
	}
	ft_memcpy(data->str->buffer, data->format_string + data->format_index, data->max_copy);
	data->str->size += data->max_copy;
	return (0);
}
