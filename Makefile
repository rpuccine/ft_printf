# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 15:37:03 by rpuccine          #+#    #+#              #
#    Updated: 2015/12/28 19:06:36 by rpuccine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_FOLDER = includes/
SRCS = ft_printf.c init.c tools.c str.c
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c $(INCLUDE_FOLDER)ft_printf.h
	$(CC) -o $@ -c $<  $(CFLAGS) -I $(INCLUDE_FOLDER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

s_fclean:
	rm -rf $(NAME)

re: fclean all
