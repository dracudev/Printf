LIB = ar
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
LIBFT_OBJ = libft/*.o
INCLUDE = ____.h

BONUS_SRC = 
BONUS_OBJ = $(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) libft
	$(LIB) rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

bonus: $(NAME) $(BONUS_OBJ)
	$(LIB) r $(NAME) $(BONUS_OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c -o $@ $<
	
libft:
	make -C libft

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all
