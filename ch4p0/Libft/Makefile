# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 18:56:45 by cormund           #+#    #+#              #
#    Updated: 2019/04/17 16:17:09 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUN = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putend.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = *.o
INCL = libft.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FUN) -c $(FLAG) -I $(INCL)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

test: re
	gcc -o test.out test.c test_printer_color.c  -L. -lft
	./test.out

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
#	/bin/rm -f test.out

re: fclean all
