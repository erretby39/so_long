NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_puthex.c\
		ft_putnm.c\
		ft_putst.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all