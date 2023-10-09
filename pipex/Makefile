NAME = pipex
CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -fsanitize=address
RM = rm -rf
SRCS = pipex.c
OBJS = $(SRCS:.c=.o)
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -LLibft -lft -o $(NAME)

$(LIBFT):
	make -C Libft

clean:
	$(RM) $(OBJS)
	make clean -C Libft 

fclean: clean
	$(RM) $(NAME)
	make fclean -C Libft 

re: fclean all

.PHONY: all clean fclean re
