#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/03/12 06:16:19 by jbulant          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIBFTDIR = libft/
OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME =	ft_printf.c \
			ft_printf_copy.c \
			ft_printf_analyze.c \
			ft_printf_close.c \
			parse_integers.c \
			parse_strings.c \
			parse_oct.c \
			parse_hex.c \
			check_status.c \
			ft_str.c \
			ft_static_itoa.c \
			ft_static_itoa_base.c

LSRCS_NAME = ft_memcpy.c \
				ft_strlen.c \
				ft_strcat.c \
				ft_toupper.c

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
