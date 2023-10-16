# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 05:20:48 by alabdull          #+#    #+#              #
#    Updated: 2023/10/16 17:27:50 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
SRCS = pipex.c free.c errors.c command_path.c
OBJS = $(SRCS:.c=.o)
LIB = ./Libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC ./Libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME) 

clean:
	@rm -f $(OBJS)
	@make clean -sC ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./Libft

re: fclean all

.PHONY: all clean fclean re