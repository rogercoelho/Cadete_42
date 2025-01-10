CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_printf.c \
	ft_putchar.c \
	ft_strlen.c \
	ft_putstr.c \
	ft_unsig.c \
	ft_itoa.c \
	ft_putint.c \
	ft_putpointer.c \
	ft_puthex.c

OBJ := $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
