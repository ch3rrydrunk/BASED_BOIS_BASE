# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 18:56:45 by cormund           #+#    #+#              #
#    Updated: 2019/04/09 21:00:42 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./srcs/
FUN = $(SRCS)ft_*.c
OBJ = ft_*.o
INLC = libft.h
FLAG = -c 
#вернуть-Wall -Wextra -Werror

all: $(NAME) $(TEST)

$(NAME) :
	gcc $(FLAG) $(FUN) $(INCL)
	ar rc $(NAME) $(OBJ)

test: re
	gcc -o test.out ./test/test.c ./test/test_printer_color.c  -L. -lft
	./test.out

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f ./test.out

re: fclean all
