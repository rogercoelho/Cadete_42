# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lello <lello@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:06:38 by rreal-de          #+#    #+#              #
#    Updated: 2024/10/18 00:58:02 by lello            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC := 	ft_isalpha.c \
		ft_isdigit.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_atoi.c \
		ft_strncmp.c \


OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)


fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
