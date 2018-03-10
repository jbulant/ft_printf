/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 22:14:49 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/10 00:15:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, va_list ap)
{
	static t_printf_data	data = {0};

	va_copy(data->args, ap);
	if (!data->ret_str)
		data->ret_str = ft_create_str();
	data->str = data->ret_str;
	
	va_end(data->args);
	return (data.ret_value);
}
