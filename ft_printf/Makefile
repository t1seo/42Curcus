# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 12:15:10 by tseo              #+#    #+#              #
#    Updated: 2020/11/04 12:15:10 by tseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./lib

INC = -I./lib -I./inc

NAME = libftprintf.a

SRC_DIR = ./src
SRC_NAME = ft_printf.c	\
			parsing_format.c \
			utils.c \
			allocating_chars_data.c \
			allocating_numbers_data.c \
			allocating_pointer_data.c \
			printing_chars_data.c \
			printing_ptr_data.c \
			printing_num_data.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_NAME))

OBJ_DIR = $(SRC_DIR)
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	cp $(LIB_DIR)/libft.a $@
	ar rc $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C ./lib clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C ./lib fclean
	rm -rf $(NAME) $(OBJS)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
