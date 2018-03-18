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

#define NOFLAG 0

typedef enum 	s_flag_delim
{
	DELIM_STR = (1 << 0),
	DELIM_UNI_STR = (1 << 1),
	DELIM_POINTER = (1 << 2),
	DELIM_INT = (1 << 3),
	DELIM_OCTAL = (1 << 4),
	DELIM_UNSIGNED = (1 << 5),
	DELIM_LHEX = (1 << 6),
	DELIM_UHEX = (1 << 7),
	DELIM_CHAR = (1 << 8),
	DELIM_UNI_CHAR = (1 << 9)
}				t_flag_delim;

typedef enum 	s_flag_spec
{
	SPEC_HASH = (1 << 0),
	SPEC_ZERO = (1 << 1),
	SPEC_MINUS = (1 << 2),
	SPEC_PLUS = (1 << 3),
	SPEC_SPACE = (1 << 4),
	SPEC_PRECISION = (1 << 5),
	SPEC_FIELD_WIDTH = (1 << 6)	
}				t_flag_spec;

typedef enum	e_flag_mod
{
	MOD_H = (1 << 0),
	MOD_HH = (1 << 1),
	MOD_L = (1 << 2),
	MOD_LL = (1 << 3),
	MOD_J = (1 << 4),
	MOD_Z = (1 << 5)
}				t_flag_mod;

typedef struct	s_printf_arg
{
	void			*content;
	t_flag_delim	delim;
	t_flag_mod		mod;
	t_flag_spec		spec;
	int				precision;
	int				width;
}				t_printf_arg;

# define STR_BUFFSIZE 4096

typedef struct	s_str
{
	char	buffer[STR_BUFFSIZE];
	size_t	size;
}				t_str;

typedef struct	s_printf_data
{
	t_str				str;
	int					ret_value;
	va_list				args;
	const char			*format_string;
	int					format_index;
	int					max_copy;
	t_printf_arg		current_arg;
	t_ft_printf_status	status;
}				t_printf_data;

typedef union 	u_ft_wchar
{
	char w[4];
	wchar_t c;
}				t_ft_wchar;

typedef struct	s_unicode
{
	wchar_t c;
	int		size;
}				t_unicode;

#define UNIBYTE1 0x80	// 0x1000 0000
#define UNIBYTE2 0xc0	// 0x1100 0000
#define UNIBYTE3 0xe0	// 0x1110 0000
#define UNIBYTE4 0xf0	// 0x1111 0000

#define MASK1 0x3f		// 0x0011 1111
#define MASK2 0x1f		// 0x0001 1111
#define MASK3 0xf		// 0x0000 1111
#define MASK4 0x7		// 0x0000 0111

t_str			*ft_create_str(void);
int				ft_printf_copy(t_printf_data *data);
int				ft_printf_analyze(t_printf_data *data);
void			check_status(t_printf_data *data);
void			ft_printf_close(t_printf_data *data);
void			print_bits(int unicode);

int				parse_int_type(t_printf_data *data);
int				parse_str_type(t_printf_data *data);
int				parse_oct(t_printf_data *data);
int				parse_hex(t_printf_data *data);
int				parse_char_type(t_printf_data *data);
int				parse_unicode(t_printf_data *data);
int				parse_unsigned_type(t_printf_data *data);
int				parse_pointer(t_printf_data *data);
int				parse_error(t_printf_data *data);

char			*ft_static_itoa_base(int nb, int base);
char			*ft_static_ltoa_base(int64_t nb, int base);
char			*ft_static_ultoa(uint64_t nb);
char			*ft_static_itoa(int nb);
char			*ft_static_ltoa(int64_t nb);

int				ft_big_putstr(t_str *str);
int				ft_big_strset(t_str *dst, char c, size_t n);
int				ft_big_strncat(t_str *dst, const char *src, size_t n);

t_printf_arg	ft_new_printf_arg(void);

t_unicode		convert_unicode(t_unicode ucode);

int				set_mod_h(t_printf_data *data);
int				set_mod_l(t_printf_data *data);
int				set_mod_j(t_printf_data *data);
int				set_mod_z(t_printf_data *data);

#endif
