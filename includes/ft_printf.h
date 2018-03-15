#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
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
	DELIM_HEX = (1 << 6),
	DELIM_CHAR = (1 << 7),
// corrige ta merde
	DELIM_UNI_CHAR = (1 << 8),
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
	t_flags				current_flags;
	t_ft_printf_status	status;
}				t_printf_data;

typedef union u_ft_wchar
{
	char w[4];
	wchar_t c;
}			t_ft_wchar;

typedef struct	s_unicode
{
	wchar_t c;
	int		size;
}				t_unicode;

#define UNIBYTE1 0x80	// 0x1000 0000
#define UNIBYTE2 0xc0	// 0x1100 0000
#define UNIBYTE3 0xe0	// 0x1110 0000
#define UNIBYTE4 0xf0	// 0x1111 0000

#define MASK2 0x3f		// 0x0011 1111
#define MASK3 0x1f		// 0x0001 1111
#define MASK4 0xf		// 0x0000 1111


t_str	*ft_create_str(void);
int		ft_printf_copy(t_printf_data *data);
int		ft_printf_analyze(t_printf_data *data);
void	check_status(t_printf_data *data);
void	ft_printf_close(t_printf_data *data);
void	print_bits(int unicode);
int		parse_int_type(t_printf_data *data);
int		parse_str_type(t_printf_data *data);
int		parse_oct(t_printf_data *data);
int		parse_hex(t_printf_data *data);
int		parse_char_type(t_printf_data *data);
int		parse_unicode(t_printf_data *data);
int		parse_unsigned_type(t_printf_data *data);
int		parse_pointer(t_printf_data *data);
char	*ft_static_itoa_base(int nb, int base);
char	*ft_static_ltoa_base(int64_t nb, int base);
char	*ft_static_ultoa(uint64_t nb);
char	*ft_static_itoa(int nb);
char	*ft_static_ltoa(int64_t nb);

#endif
