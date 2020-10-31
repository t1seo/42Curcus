CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
SRCS = $(filter-out $(SRCS_BONUS), $(wildcard *.c))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rc $@ $^

all : $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
