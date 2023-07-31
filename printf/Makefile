# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 12:14:58 by vlomakin          #+#    #+#              #
#    Updated: 2023/07/31 12:15:53 by vlomakin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = 


OBJ =	$(SRC:.c=.o)

OBJ_B =	$(SRC_B:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ) $(OBJ_B)
	@$(AR) $(NAME) $(OBJ) $(OBJ_B)

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME) $(OBJ) $(OBJ_B)

re: fclean all

.PHONY: bonus all clean fclean re