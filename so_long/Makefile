CC = cc
CFLAGS = -Wall -Wextra -Werror 
                        # -g3 -fsanitize=address
NAME = so_long
SRC = so_long.c
OBJ = ${SRC:.c=.o}

MLX = cd mlx && make

# MLX_DIR = ./mlx
# UNAME := $(shell uname)

# ifeq ($(UNAME), Linux)
#     INCLUDES = -I/usr/include -Imlx
#     MLX_LIB = $(MLX_DIR)/libmlx_linux.a
#     MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# else
#     INCLUDES = -I/opt/X11/include -Imlx
#     MLX_LIB = $(MLX_DIR)/libmlx_macos.a
#     MLX_FLAGS = -Lmlx -lmlx -L/opt/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
# endif
# .c.o:
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
		$(MLX)
	    @$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address

all: $(NAME)

clean:
	@rm -f $(OBJ)
	$(MAKE) clean -C mlx

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
