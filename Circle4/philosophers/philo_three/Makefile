CC = gcc
FLAG = -Wall -Wextra -Wextra

INCLUDE = ./
SRCS = main.c \
	   message.c \
	   parser.c \
	   utils.c \
	   setting.c \
	   routine.c \
	   checker.c \
	   check_process.c

DEBUG = -g -fsanitize=address
NAME = philo_three
OBJS = ${SRCS:.c=.o}

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o) -I $(INCLUDE)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) $(DEBUG) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
