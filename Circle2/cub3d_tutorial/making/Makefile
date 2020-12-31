TARGET = cub3D
INCLUDES = -I ./inc
CFLAGS =
MLX_FLAGS = -L./mlx
MLX_LIBS = -lmlx -framework OpenGL -framework AppKit
LIBFT_FLAGS = -L./libft
LIBFT_LIBS = -lft
CC = gcc
RM = rm -f

SRCS = $(wildcard *.c **/*.c **/**/*.c)
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_LIBS) $(LIBFT_FLAGS) $(LIBFT_LIBS) -o $@ $^
	./cub3d

bonus : all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
