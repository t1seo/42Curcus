CC = gcc
FLAG = -Wall -Wextra -Wextra
INCLUDE = ./
SRCS = main.c
NAME = philo_one

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o) $(INCLUDE)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
