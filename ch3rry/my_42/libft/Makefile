# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/04/10 13:43:47 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libft.a

TEST := test.out

HEADER := libft.h

#FLAGS := "-Wall -Wextra -Werror"

OBJECTS := $(patsubst %.c,%.o,$(wildcard ft_*.c))

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc .
$(OBJECTS) : $(wildcard *.c)
	$(CC) -o $@ $?

test : re
	@gcc -o $(TEST) test_func.c test_printer_color.c -L. -lft
	@./$(TEST)
#	@echo "HEIL CHERRY, here are your tests... Please enjoy!" > text; cat text | say; rm -rf text
	@norminette ft_*.c

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(TEST) test_func.o

re : fclean all

print: *.c
	lpr -p $?
	touch print
