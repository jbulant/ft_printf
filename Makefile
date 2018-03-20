NAME = libftprintf.a

LIBFTDIR = libft/
OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME =	ft_printf.c \
			ft_printf_copy.c \
			ft_printf_analyze.c \
			ft_printf_close.c \
			ft_printf_setspec.c \
			print_bits.c \
			ft_modifiers.c \
			parse_integers.c \
			parse_strings.c \
			parse_char.c \
			parse_oct.c \
			parse_hex.c \
			parse_unicode.c \
			parse_unsigned.c \
			parse_pointer.c \
			parse_error.c \
			parse_specifiers.c \
			parse_sharp.c \
			convert_unicode.c \
			check_status.c \
			ft_static_itoa.c \
			ft_static_itoa_base.c \
			ft_static_ltoa.c \
			ft_static_ultoa.c \
			ft_static_ltoa_base.c \
			ft_static_ultoa_base.c \
			ft_utilities.c \
			ft_casts.c

LSRCS_NAME = ft_memcpy.c \
				ft_putchar.c \
				ft_strlen.c \
				ft_strcat.c \
				ft_toupper.c \
				ft_bzero.c \
				ft_memalloc.c \
				ft_memset.c \
				ft_atoi.c \
				ft_isspace.c \
				ft_isdigit.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LOBJS = $(addprefix $(LIBFTDIR),$(LSRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft

HEADER_DIR = includes/
HEADER_NAME = ft_printf.h libft.h

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -lasan -g3

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADER}
	@mkdir -p objs
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFTDIR)%.o: $(LIBFTDIR)%.c ${HEADER}
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS) $(LOBJS)
	ar rc $(NAME) $(OBJS) $(LOBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
