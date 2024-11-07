# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lello <lello@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:06:38 by rreal-de          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/11/05 19:41:21 by lello            ###   ########.fr        #
=======
#    Updated: 2024/11/06 20:40:32 by rreal-de         ###   ########.fr        #
>>>>>>> refs/remotes/origin/main
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
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \

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
