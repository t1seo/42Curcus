CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft

INC = -I./libft -I./header

NAME = libftprintf.a

SRC_DIR = ./src
SRC_NAME = ft_printf.c	\
			parsing_format.c \
			utils.c \
			allocating_chars_data.c \
			allocating_numbers_data.c \
			allocating_pointer_data.c \
			aligning_chars.c \
			aligning_numbers.c \
			aligning_pointer.c 
			
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
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(OBJS)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
