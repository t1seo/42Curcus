NAME = libasm.a

SRCS = ./srcs/ft_strlen.s \
		./srcs/ft_strcpy.s \
		./srcs/ft_strcmp.s \
		./srcs/ft_write.s \
		./srcs/ft_read.s \
		./srcs/ft_strdup.s

OBJS = $(SRCS:.s=.o)

TEST = test

%.o	: %.s
	nasm -f macho64 $<

all	: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(TEST) $(NAME)

re : fclean all

test : re
	gcc main.c -o test -L. -lasm

