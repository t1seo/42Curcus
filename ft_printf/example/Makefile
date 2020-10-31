CC = gcc
CFLAGS = 

LIB_DIR = ./lib

INC = -I./lib -I./header

NAME = libftprintf.a

SRC_DIR = ./src
SRC_NAME = ft_printf.c	\
			ft_printf_char.c \
			ft_printf_int.c \
			ft_printf_make.c \
			ft_printf_make_char.c \
			ft_printf_make_int.c \
			ft_printf_parsing.c \
			ft_printf_utils.c
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
