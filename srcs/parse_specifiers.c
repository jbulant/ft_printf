#include "ft_printf.h"

void		parse_precision(t_printf_data *data)
{
	int		i;

	if (!(data->current_arg.spec & SPEC_PRECISION)
		|| (i = (int)data->current_arg.precision - data->current_arg.size) <= 0)
		return ;
	data->ret_value += ft_big_strset(&data->str, '0', (size_t)i);
}

void		parse_width(t_printf_data *data)
{
	int		i;

	if (!(data->current_arg.spec & SPEC_FIELD_WIDTH)
		|| (i = (int)data->current_arg.width - data->current_arg.size) <= 0
		|| (data->current_arg.spec & SPEC_PRECISION
		&& (i = (int)data->current_arg.width - data->current_arg.precision)
			<= 0))
		return ;
	data->ret_value += ft_big_strset(&data->str, ' ', (size_t)i);
}