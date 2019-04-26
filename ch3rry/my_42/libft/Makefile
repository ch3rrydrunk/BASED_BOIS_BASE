# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/04/25 15:07:49 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libft.a

TEST := test.out

#FLAGS := -g -Wall -Wextra -Werror

NAME := libft.a

INCLUDE := .

SOURCE = $(wildcard ft_*.c)

OBJECTS = $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o : %.c libft.h
	$(CC) -c $(FLAGS) $(SOURCE) -I$(INCLUDE)

test : re
	@gcc -o $(TEST) test_func.c test_printer_color.c -L. -lft
	@./$(TEST)
#	@echo "HEIL CHERRY, here are your tests... Please enjoy!" > text; cat text | say; rm -rf text
	@norminette ft_*.c

clean :
	@rm -rf $(wildcard ft_*.o)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(TEST) test_func.o

re : fclean all
