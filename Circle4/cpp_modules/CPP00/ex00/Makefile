CC = clang++
OPT = -std=c++98
FLAGS = -Wall -Wextra -Werror

NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) $(OPT) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OPT) $(OBJS) -o $(NAME)

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .cpp.o