#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define PRINTF_ATTR __attribute__ ((format (printf, 1, 2)))
int	ft_printf(const char *format, ...) PRINTF_ATTR;

# define TREATING(x) x != 0

typedef enum	e_ft_printf_status
{
	FINISH = 0,
	COPYING = 1,
	ANALYZING_PERCENT = 2
}				t_ft_printf_status;

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
	t_str				*root_str;
	t_str				*str;
	int					ret_value;
	va_list				args;
	const char			*format_string;
	int					format_index;
	int					max_copy;
	t_ft_printf_status	status;
}				t_printf_data;

t_str	*ft_create_str(void);
int		ft_printf_copy(t_printf_data *data);
int		ft_printf_analyze(t_printf_data *data);
void	check_status(t_printf_data *data);
void	ft_printf_close(t_printf_data *data);

#endif
