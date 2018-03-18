#include "ft_printf.h"

int			set_mod_hh(t_printf_data *data)
{
	data->format_index++;
	if (data->current_arg.mod < MOD_HH)
		data->current_arg.mod = MOD_HH;
	return (0);
}

int			set_mod_h(t_printf_data *data)
{
	if (data->format_string[data->format_index + 1] == 'h')
		return (set_mod_hh(data));
	if (data->current_arg.mod < MOD_H)
		data->current_arg.mod = MOD_H;
	return (0);
}

int			set_mod_ll(t_printf_data *data)
{
	data->format_index++;
	if (data->current_arg.mod < MOD_LL)
		data->current_arg.mod = MOD_LL;
	return (0);
}

int			set_mod_l(t_printf_data *data)
{
	if (data->format_string[data->format_index + 1] == 'l')
		return (set_mod_ll(data));
	if (data->current_arg.mod < MOD_L)
		data->current_arg.mod = MOD_L;
	return (0);
}

int			set_mod_j(t_printf_data *data)
{
	if (data->current_arg.mod < MOD_L)
		data->current_arg.mod = MOD_L;
	return (0);
}

int			set_mod_z(t_printf_data *data)
{
	if (data->current_arg.mod < MOD_Z)
		data->current_arg.mod = MOD_Z;
	return (0);
}