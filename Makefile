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

# Tool and flag definitions
LIB = ar rcs
RM = rm -f
MKDIR_P = mkdir -p

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = libftprintf.a

# Source files and paths
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/%.o, $(SRC))
DEPS = $(patsubst src/%.c, bin/%.d, $(SRC))

# Default target
all: $(NAME)

# Rule to build the static library
$(NAME): $(OBJ) libft/libft.a
	$(LIB) $(NAME) $(OBJ) libft/libft.a

# Rule to compile .c files to .o files in bin/
bin/%.o: src/%.c
	@$(MKDIR_P) $(dir $@)
	$(CC) $(CCFLAGS) -MMD -c $< -o $@

# Build the libft.a library
libft/libft.a:
	@$(MAKE) -C libft

# Clean up object and dependency files
clean: libft_clean
	$(RM) -r bin/

# Clean up everything including the static library
fclean: clean libft_fclean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Clean targets in libft
libft_clean:
	@$(MAKE) clean -C libft

libft_fclean:
	@$(MAKE) fclean -C libft

# Include dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re libft_clean libft_fclean
