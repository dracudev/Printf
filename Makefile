# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antandre <antandre@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 11:56:18 by antandre          #+#    #+#              #
#    Updated: 2024/07/17 12:56:07 by antandre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = ft_printf.c ft_text.c ft_numbers.c
OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)
INCLUDE = ft_printf.h

all: $(NAME) libft.a

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ) libft/libft.a

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CCFLAGS) -MMD -c $< -o $@

libft.a: 
	make -C libft

clean: libft_clean
	$(RM) $(OBJ) $(DEPS)

fclean: clean libft_fclean
	$(RM) $(NAME)

libft_clean: 
	make clean -C libft

libft_fclean:
	make fclean -C libft

re: fclean all

-include $DEPS

.PHONY: all clean fclean re
