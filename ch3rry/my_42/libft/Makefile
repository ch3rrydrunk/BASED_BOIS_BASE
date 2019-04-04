# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 16:54:30 by caellis           #+#    #+#              #
#    Updated: 2019/04/04 19:30:01 by caellis          ###   ########.fr        #
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
	@gcc -o $(TEST) test_func.c -L. -lft
	@./$(TEST)
#	@norminette *.c

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(TEST) test_func.o

re : fclean all
