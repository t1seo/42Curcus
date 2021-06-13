CC = clang++
OPT = -std=c++98
FLAGS = -Wall -Wextra -Werror

NAME = convert
SRCS = Convert.cpp \
	   main.cpp
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

run: $(NAME)
	./$(NAME) 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
	./$(NAME) inf
	./$(NAME) -inf
	./$(NAME) nan
	./$(NAME) 2147483647
	./$(NAME) 2147483648
	./$(NAME) -2147483648
	./$(NAME) -2147483649
	./$(NAME) 0
	./$(NAME) 3.14f
	


.PHONY: all clean fclean re .cpp.o