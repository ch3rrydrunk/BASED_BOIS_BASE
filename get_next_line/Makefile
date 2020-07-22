# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:04:08 by caellis           #+#    #+#              #
#    Updated: 2020/07/21 19:39:37 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := test_gnl

FLAGS := -Wall -Wextra -g

LIB := ./libft/libft.a
OBJ_DIR=./obj
SRC_DIR=./

SOURCE := $(wildcard *.c)
OBJECTS := $(addprefix $(OBJ_DIR)/, $(SOURCE:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(LIB):
	@make -C libft/

$(NAME): $(OBJ_DIR) $(OBJECTS) $(LIB)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME)

clean :
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJECTS)
	@make -C libft/ clean

fclean : clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re : fclean all
