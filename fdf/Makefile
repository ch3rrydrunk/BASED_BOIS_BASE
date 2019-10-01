# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 16:40:19 by ch3rryhq          #+#    #+#              #
#    Updated: 2019/10/01 13:17:06 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRC_DIR=./src
HDR_DIR=./include
LIB_DIR :=./libft
OBJ_DIR=./obj
MLX_DIR=./minilibx_macos

CC=gcc
CC_FLAGS= -g
MLX_CC_FLAGS=-lmlx -framework OpenGL -framework AppKit

SRC_FILES=\
	fdf.c\
	vector.c

HDR_FILES=\
	fdf.h\
	mlx.h\
	libft.h\
	keys.h

LIB_FILE=\
	libft.a

MLX_FILE=\
	libmlx.a

SRC=$(addprefix $(SRC_DIR)/, $(SRC_FILES))
HDR=$(addprefix $(HDR_DIR)/, $(HDR_FILES))
OBJ=$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
LIB=$(addprefix $(LIB_DIR)/, $(LIB_FILE))
MLX=$(addprefix $(MLX_DIR)/, $(MLX_FILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	@$(CC) $(CC_FLAGS) -I$(HDR_DIR) -c $< -o $@ 

$(NAME): $(LIB) $(MLX) $(OBJ)
	@$(CC) $(CC_FLAGS) $(MLX_CC_FLAGS) $(OBJ) $(MLX) $(LIB) -o $@ 

clean :
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean

fclean : clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@/bin/rm -f $(MLX)

re : fclean all

.PHONY: -
