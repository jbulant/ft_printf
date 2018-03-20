#include "ft_printf.h"

char	*(*test(int i))()
{
	static char *(*f[5])() = {ft_static_ultoa_base, ft_static_ultoa, ft_static_ultoa_base, ft_static_ultoa_base, ft_static_ltoa};
	return (f[i]);
}

void	convert_basic(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	*(int*)c = va_arg(data->args, int);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	convert_h(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	*(short*)c = va_arg(data->args, int);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	convert_hh(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	c[0] = va_arg(data->args, int);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	convert_l(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	*(long*)c = va_arg(data->args, long);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	convert_ll(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	*(long long*)c = va_arg(data->args, long long);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	convert_j(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	*(intmax_t*)c = va_arg(data->args, intmax_t);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	convert_z(t_printf_data *data)
{
	char	c[8];

	*(uint64_t *)c = 0;
	*(size_t*)c = va_arg(data->args, size_t);
	if (data->current_arg.delim == DELIM_OCTAL)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 8);
	else if (data->current_arg.delim == DELIM_UHEX 
		|| data->current_arg.delim == DELIM_LHEX)
		data->current_arg.content = ft_static_ultoa_base(*(uint64_t*)c, 16);
	else if (data->current_arg.delim == DELIM_UNSIGNED)
		data->current_arg.content = ft_static_ultoa(*(uint64_t*)c);
	else
		data->current_arg.content = ft_static_ltoa(*(int64_t*)c);
}

void	ft_casts(t_printf_data *data)
{
	static void		(*convert[7])(t_printf_data *) = {convert_basic, convert_hh, convert_h, convert_l, convert_ll, convert_j, convert_z};
	size_t			i;
	char			*str;

	// printf("i == %zu\n", i);
	convert[data->current_arg.mod](data);
	str = (char*)data->current_arg.content;
	i = ft_strlen(str);
	data->current_arg.size = i;
	data->current_arg.total_size += i;
	parse_width(data);
	if (data->current_arg.delim <= DELIM_UHEX
		&& !(data->current_arg.spec & SPEC_MINUS))
		parse_sharp(data);
	parse_precision(data);
}