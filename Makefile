# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:32:55 by yanaranj          #+#    #+#              #
#    Updated: 2023/12/06 16:30:37 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

HEADER = ft_printf.h

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_hexadecimal.c	\
	  ft_unsignednbr.c ft_pointer.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(AR) $(NAME) $(OBJS)

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
