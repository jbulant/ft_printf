NAME = libftprintf.a

LIBFTDIR = libft/
OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME =	ft_printf.c \
			ft_printf_copy.c \
			ft_printf_analyze.c \
			ft_printf_close.c \
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
			convert_unicode.c \
			check_status.c \
			ft_static_itoa.c \
			ft_static_itoa_base.c \
			ft_static_ltoa.c \
			ft_static_ultoa.c \
			ft_static_ltoa_base.c \
			ft_utilities.c

LSRCS_NAME = ft_memcpy.c \
				ft_putchar.c \
				ft_strlen.c \
				ft_strcat.c \
				ft_toupper.c \
				ft_bzero.c \
				ft_memalloc.c \
				ft_memset.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LOBJS = $(addprefix $(LIBFTDIR),$(LSRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFTDIR)%.o: $(LIBFTDIR)%.c
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
