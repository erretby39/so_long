NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX_FLAG = -Iincludes_mlx -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
CFILES = get_next_line.c get_next_line_utils.c so_long.c error.c \
	map_chek.c parsing.c split_utils.c utils.c move.c

OFILSE = $(CFILES:.c=.o)
PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF) $(OFILSE)
	$(CC) $(CFLAGS) $(OFILSE) $(PRINTF) $(MLX_FLAG) -o $(NAME)

$(PRINTF) :
	make -C printf

clean:
	rm -f $(OFILSE)
	make clean -C printf

fclean: clean
	rm -f $(NAME)
	make fclean -C printf

re: fclean all