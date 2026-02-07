SRC = main.cpp \
	PmergeMe.cpp

CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98 -g
OBJS = $(SRC:.cpp=.o)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all


.PHONY: all clean fclean re