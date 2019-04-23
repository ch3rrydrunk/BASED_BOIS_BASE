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

NAME := libft.a

TEST := test.out

SOURCE := ft_*.c

#FLAGS := -Wall -Wextra -Werror

OBJECTS := OBJECTS := ft_atoi.o ft_islower.o ft_memccpy.o ft_putstr.o ft_strlcat.o \
ft_strrchr.o ft_bzero.o ft_isprint.o ft_memchr.o ft_strcat.o ft_strlen.o \
ft_strstr.o ft_isalnum.o ft_isspace.o ft_memcmp.o ft_strchr.o ft_strncat.o \
ft_tolower.o ft_isalpha.o ft_isupper.o ft_memcpy.o ft_strcmp.o ft_strncmp.o \
ft_toupper.o ft_isascii.o ft_makestr.o ft_memmove.o ft_strcpy.o ft_strncpy.o \
ft_isdigit.o ft_memalloc.o ft_memset.o ft_strdup.o ft_strnstr.o

ft_%.o : ft_%.c
        $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

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
