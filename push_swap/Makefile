# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caellis <caellis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 15:47:32 by ch3rryhq          #+#    #+#              #
#    Updated: 2020/03/08 18:25:48 by caellis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER=checker

OS			=	$(shell uname -s)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

SRC_FILES	=			\
	checker.c			\
	commands.c

HDR_FILES	=			\
	push_swap.h

DIR_SRC		=	./src
DIR_INC		=	./include
DIR_OBJ		=	./obj

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

FT_PRINTF		=	./ft_printf/libftprintf.a
FT_PRINTF_DIR	=	./ft_printf

SRC			=	$(addprefix $(DIR_SRC)/, $(SRC_FILES))
HDR			=	$(addprefix $(DIR_INC)/, $(HDR_FILES))
OBJ			=	$(addprefix $(DIR_OBJ)/, $(SRC_FILES:.c=.o))

INCLUDES	=	-I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)/include -I $(DIR_INC)
LIBS		:=	./libft/libft.a ./ft_printf/libftprintf.a

LIBS	:= $(LIBS)

all: $(CHECKER)

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)

$(CHECKER): $(DIR_OBJ) $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(CHECKER) $(SDL_LINK)

$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c $(HDR)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT): FAKE
	@$(MAKE) -C $(LIBFT_DIR)/ --no-print-directory

$(FT_PRINTF): FAKE
	@$(MAKE) -C $(FT_PRINTF_DIR)/ --no-print-directory

clean :
	@/bin/rm -rf $(DIR_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean : clean
	@/bin/rm -f $(CHECKER) $(addprefix tests/test_,$(FILE_NAMES))
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@/bin/rm -f $(addprefix tests/,$(TEST_NAMES))

re : fclean all

.PHONY: FAKE
