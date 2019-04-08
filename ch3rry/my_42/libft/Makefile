# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2019/04/08 16:41:59 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

TEST := test.out

SOURCE := ft_*.c

#FLAGS := -Wall -Wextra -Werror

HEADERS :=

OBJECTS := ft_*.o

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SOURCE)
	@ar rc $(NAME) $(OBJECTS)

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
