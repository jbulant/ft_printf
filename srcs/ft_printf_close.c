#include "ft_printf.h"

void	ft_printf_close(t_printf_data *data)
{
	if (data->ret_value == -1)
	{
		while (data->root_str)
		{
			write(1, data->root_str->buffer, data->root_str->size);
			data->str = data->root_str;
			data->root_str = data->root_str->next;
			free(data->str);
		}
	}
	else
	{
		while(data->root_str)
		{
			write(1, data->root_str->buffer, data->root_str->size);
			data->ret_value += data->root_str->size;
			data->str = data->root_str;
			data->root_str = data->root_str->next;
			free(data->str);
		}
	}
	data->root_str = NULL;
	data->current_flags = 0;
}
