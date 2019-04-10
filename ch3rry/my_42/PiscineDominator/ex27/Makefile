# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 15:28:03 by caellis           #+#    #+#              #
#    Updated: 2019/04/04 10:42:38 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_display_file

SOURCE := ./srcs/ft_error.c ./srcs/main.c ./srcs/ft_strlen.c

HEADERS := includes

FLAGS := -Wall -Wextra -Werror

OBJECTS := ft_error.o main.o ft_strlen.o

all : $(NAME)

$(NAME) : 
	@gcc -I $(HEADERS) -c $(SOURCE)
	@gcc $(FLAGS) -o $(NAME) $(OBJECTS)

clean :
	@rm -f $(OBJECTS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
