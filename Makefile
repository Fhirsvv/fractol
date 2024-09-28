# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 16:26:21 by ecortes-          #+#    #+#              #
#    Updated: 2024/09/28 17:20:02 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./src
SRC = main.c

OBJS = $(ADDPREFIX $(SRC_DIR)/, $(SRC:=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

MLX_PATH = minilibx-linux/
MINILIBX:= -Lminilibx-linux -lmlx-linux -lXext -lX11 -lm -lz

all: $(NAME)
$(NAME): $(OBJS)	
	@make  -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)
clean:
	$(RM) $(OBJS) $(LIBFT_A)

fclean: clean	
	@$(RM) $(NAME) $(B_NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean	

re: fclean	
	@make all

.PHONY: all  clean fclean re
