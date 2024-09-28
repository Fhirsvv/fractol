# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 16:26:21 by ecortes-          #+#    #+#              #
#    Updated: 2024/09/28 18:54:11 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Iminilibx-linux -Wall -Wextra -Werror

# Library flags
LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# Source files
SRC = src/main.c src/inti.c src/render.c src/utils.c

# Object files (replace .c with .o)
OBJ = $(SRC:.c=.o)

# Output executable name
NAME = fractol

# Default target
all: $(NAME)

# Linking the executable
$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compiling each .c file into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re

