#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/02/12 00:45:05 by jbulant          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIBFT = libft.a

LIBFTDIR = libft/

OBJDIR = objs
SRCSDIR = srcs

SRCS_NAME =	ft_printf.c
OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCSDIR)/,$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR)/,$(OBJS_NAME))

INCLUDES = includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling: $(NAME)"
	@ar rc $(NAME) $(OBJ) $(LIBFTDIR)$(LIBFT)
	@ranlib $(NAME)
	@echo "Done."

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p objs
	@echo "Making: OBJ"
	@$(CC) $(CFLAGS) $(OPTIFLAGS) -I$(INCLUDES) -c $(SRCS)
	@mv $(OBJS_NAME) $(OBJDIR)
	@echo "Done."

$(LIBFT):
	@echo "Making: libft"
	@make -C libft/
	@echo "Done."

clean:
	@echo "OBJ CLEANING: libft"
	@cd libft && make clean
	@echo "OBJ CLEANING: $(NAME)"
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "FILE CLEANING: libft"
	@cd libft && make fclean
	@echo "FILE CLEANING: $(NAME)"
	@rm -rf $(NAME) $(IMGFOLDER)
	@echo "FILE CLEANING: $(IMGFOLDER)"

re: fclean all
