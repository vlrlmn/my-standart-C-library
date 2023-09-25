NAME = pipex
CC = cc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf
SRCS = pipex.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS)
	make clean -C libft 

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft 

re: fclean all

.PHONY: all clean fclean re
