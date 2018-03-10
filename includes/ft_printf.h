/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 22:05:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/10 00:20:54 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define A __attribute__ ((format (printf, 1, 2)))
int	ft_printf(const char *format, ...) A;
# undef A

typedef enum	e_flags
{
	DELIM_STR = (1 << 0),
	DELIM_UNI_STR = (1 << 1),
	DELIM_POINTER = (1 << 2),
	DELIM_INT = (1 << 3),
	DELIM_OCTAL = (1 << 4),
	DELIM_UNSIGNED = (1 << 5),
	DELIM_LOWER_HEX = (1 << 6),
	DELIM_UPPER_HEX = (1 << 7),
	DELIM_CHAR = (1 << 8),
	DELIM_UNI_CHAR = (1 << 9),
	SPEC_HASH = (1 << 10),
	SPEC_ZERO = (1 << 11),
	SPEC_MINUS = (1 << 12),
	SPEC_PLUS = (1 << 13),
	SPEC_SPACE = (1 << 14),
	SPEC_DOT = (1 << 15),
	MOD_H = (1 << 16),
	MOD_HH = (1 << 17),
	MOD_L = (1 << 18),
	MOD_LL = (1 << 19),
	MOD_J = (1 << 20),
	MOD_Z = (1 << 21)
}				t_flags;

# define STR_BUFFSIZE 4096

typedef struct	s_str
{
	char			buffer[STR_BUFFSIZE];
	size_t			size;
	struct s_str	*next;
}				t_str;

typedef struct	s_printf_data
{
	t_str		*ret_str;
	t_str		*str;
	int			ret_value;
	va_list		*args;
	char		*format_string;
}				t_printf_data;

t_str	*ft_create_str(void);

#endif
