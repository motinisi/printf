# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timanish <timanish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 21:56:14 by timanish          #+#    #+#              #
#    Updated: 2025/04/03 21:29:09 by timanish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFRAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = 	ft_putword.c\
		ft_printf.c\
		ft_adrlogic.c\
		
OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

$(NAME) :    $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:%.c
	$(CC) -c  $(CFLAGS) $^ -o $@ $(INCLUDES)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re