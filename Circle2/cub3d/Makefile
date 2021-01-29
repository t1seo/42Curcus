# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 19:32:08 by tseo              #+#    #+#              #
#    Updated: 2021/01/27 12:33:08 by tseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFALGS = -Wall -Wextra -Werror
RM = rm -f
FRAMEWORK = -framework OpenGL -framework AppKit

NAME = cub3d
INCLUDES = ./inc
SRCS_DIR = ./src
SRCS_FILES = main.c \
			gnl.c \
			parsing_map.c \
			parsing_path.c \
			parsing_color.c \
			parsing_color_util.c \
			parsing_map_util_1.c \
			parsing_map_util_2.c \
			charset_split.c \
			measuring_map_size.c \
			map_validation.c \
			map_validation_util.c \
			check_arguments.c \
			initial_setting.c \
			initial_setting_util.c \
			key_handling.c \
			player_moving.c \
			loading_image.c \
			drawing.c \
			making_map.c \
			making_map_util.c \
			wall_casting.c \
			wall_casting_calc.c \
			sprite_casting.c \
			sprite_casting_util.c \
			sprite_casting_calc.c \
			saving_bmp.c \
			error_util.c \
			debugging_util.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)


LIBFT_NAME = ft
LIBFT_DIR = ./libft
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

MLX_NAME = mlx_opengl
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR), libmlx_opengl.a)

MLX_BETA_NAME = mlx
MLX_BETA_DIR = ./mlx_beta
MLX_BETA = $(addprefix $(MLX_BETA_DIR), libmlx.dylib)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(MAKE) -C $(MLX_DIR) all
	$(MAKE) -C $(MLX_BETA_DIR) all
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME) -L$(MLX_BETA_DIR) -l$(MLX_BETA_NAME) $(FRAMEWORK) $^ -o $@
	install_name_tool -change libmlx.dylib mlx_beta/libmlx.dylib cub3d

$(SRCS_DIR)/$.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(MLX_BETA_DIR) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(MLX_BETA_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(MLX_BETA_DIR) clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

