SRC = ft_isalnum.c ft_strlen.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strdup.c \ 
#ft _isalpha.c ft_isascii.c

	OBJ = $(SRC:.c =.o)

	CC = cc

	CFLAGS = -Wall - Werror - Wextra

	NAME = libft.a

	all : $(NAME)

	$(NAME): $(OBJ)
	ar -rcs 
	
	$(NAME) $(OBJ)

	clean : rm -f $(OBJ)

	fclean : clean rm -f
	
	$(NAME)re : fclean all

	.PHONY : all clean fclean re