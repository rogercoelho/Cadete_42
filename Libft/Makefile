# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lello <lello@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 17:34:48 by rreal-de          #+#    #+#              #
#    Updated: 2024/11/12 03:18:06 by lello            ###   ########.fr        #
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
		ft_strdup.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memset.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strmapi.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \

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
