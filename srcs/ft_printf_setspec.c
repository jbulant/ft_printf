#include "ft_printf.h"
int				set_precision(t_printf_data *data)
{
	int		i;
	int		j;

	if (data->current_arg.spec & SPEC_PRECISION
		|| data->current_arg.mod)
		return (parse_error(data));
	data->current_arg.spec |= SPEC_PRECISION;
	if (data->format_string[data->format_index + 1] == '*')
	{
		data->current_arg.precision = va_arg(data->args, unsigned int);
		data->format_index++;
		printf("prec set: %u\n", data->current_arg.precision);
		return (0);
	}
	data->current_arg.precision = ft_atoi(data->format_string
										+ data->format_index + 1);
	j = (data->current_arg.precision < 10
		&& !ft_isdigit(data->format_string[data->format_index + 1])) ? 0 : 1;
	i = data->current_arg.precision;
	while ((i /= 10))
		j++;
	data->format_index += (size_t)j;
	printf("prec set: %u\n", data->current_arg.precision);
	return (0);
}
/*

%.0p 


*/
int				set_width_wildcard(t_printf_data *data)
{
	if (data->current_arg.spec & (SPEC_PRECISION | SPEC_FIELD_WIDTH)
		|| data->current_arg.mod)
		return (parse_error(data));
	data->current_arg.spec |= SPEC_FIELD_WIDTH;
	data->current_arg.width = va_arg(data->args, unsigned int);
	printf("width set: %u\n", data->current_arg.width);
	return (0);
}

int				set_width_digit(t_printf_data *data)
{
	int		i;
	int		j;

	if (data->current_arg.spec & (SPEC_PRECISION | SPEC_FIELD_WIDTH)
		|| data->current_arg.mod)
		return (parse_error(data));
	data->current_arg.spec |= SPEC_FIELD_WIDTH;
	data->current_arg.width = ft_atoi(data->format_string + data->format_index);
	j = 0;
	i = data->current_arg.width;
	while ((i /= 10))
		j++;
	data->format_index += (size_t)j;
	printf("width set: %u\n", data->current_arg.width);
	return (0);
}