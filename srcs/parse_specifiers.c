#include "ft_printf.h"

void		parse_precision(t_printf_data *data)
{
	int		i;

	if (!(data->current_arg.spec & SPEC_PRECISION)
		|| (i = (int)data->current_arg.precision - data->current_arg.size) <= 0)
		return ;
	//if (data->current_arg.spec & SPEC_MINUS)
	  //  data->ret_value += ft_big_strset(&data->str + , '0', (size_t)i);
	//	  i = -(int)data->current_arg.precision + data->current_arg.size; //printf("i == %d\n", i);
	//	  data->ret_value += ft_big_strset(&data->str, '0', (size_t)i);
	//else
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
	int truc = data->current_arg.precision;//+data->current_arg.width;
	printf("truc == %d, i == %d\n", truc, i);
	if (data->current_arg.spec & SPEC_MINUS)
	  data->ret_value += ft_big_strset_off(&data->str, truc, ' ', (size_t)i);
	else
	  data->ret_value += ft_big_strset(&data->str, ' ', (size_t)i);
}

void		parse_minus(t_printf_data *data)
{
	(void)data;
//	if ()
//		return ;
//	data->
}
