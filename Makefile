# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antandre <antandre@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 11:56:18 by antandre          #+#    #+#              #
#    Updated: 2024/07/16 12:49:23 by antandre         ###   ########.fr        #
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

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CCFLAGS) -MMD -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $DEPS

.PHONY: all clean fclean re
