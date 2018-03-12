#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/03/12 02:07:41 by jbulant          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIBFTDIR = libft
OBJDIR = objs
SRCSDIR = srcs

SRCS_NAME =	ft_printf.c \
			ft_printf_copy.c \
			ft_printf_analyze.c \
			ft_printf_close.c \
			check_status.c

LIBSRCS_NAME = ft_memdel.c

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCSDIR)/,$(SRCS_NAME))
LIBSRCS = $(addprefix $(LIBFTDIR)/,$(LIBSRCS_NAME);
OBJS = $(addprefix $(OBJDIR)/,$(OBJS_NAME))
LIBOBJS = $(addprefix $(LIBFTDIR)/,$(LIBOBJS_NAME))

INCLUDES = includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g
DEBUGFLAGS = -fsanitize=address -g3

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p objs
	@echo "Making: OBJ"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<
	@echo "Done."

$(LIBFTDIR)/%.o: $(LIBFTDIR)/%.c
	@mkdir -p objs
	@echo "Making: LIBFTOBJ"
	@$(CC) $(CFLAGS) -c - $@ $<
	@echo "Done."

$(NAME): $(OBJS) $(LIBOBJS)
	@echo "Compiling: $(NAME)"
	@ar rc $(NAME) $(OBJ) $(LIBOBJS)
	@ranlib $(NAME)
	@echo "Done."

clean:
	@echo "OBJ CLEANING: libft"
	@cd libft && make clean
	@echo "OBJ CLEANING: $(NAME)"
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "FILE CLEANING: $(NAME)"
	@rm -rf $(NAME) $(IMGFOLDER)
	@echo "FILE CLEANING: $(IMGFOLDER)"

re: fclean all
