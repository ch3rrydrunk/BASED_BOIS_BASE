# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 16:54:30 by caellis           #+#    #+#              #
#    Updated: 2019/04/04 18:56:01 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SOURCE := ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c

HEADERS := includes

OBJECTS := ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all : $(NAME)

$(NAME) :
	gcc -I $(HEADERS) -c $(SOURCE)
	ar rc $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
