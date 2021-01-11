# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 19:32:08 by tseo              #+#    #+#              #
#    Updated: 2021/01/10 20:10:27 by tseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFALGS = -Wall -Wextra -Werror
RM = rm -f
FRAMEWORK = -framework OpenGL -framework AppKit

NAME = cub3d
INCLUDES = ./inc
SRCS_DIR = ./src
SRCS_FILES = main.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)


LIBFT_NAME = ft
LIBFT_DIR = ./libft
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR), libmlx.a)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME) $(FRAMEWORK) $^ -o $@

$(SRCS_DIR)/$.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
