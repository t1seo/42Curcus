
CC = clang++
OPT = -std=c++98
FLAG = -Wall -Wextra -Werror

NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAG) $(OPT) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OPT) $(OBJS) -o $(NAME)

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
