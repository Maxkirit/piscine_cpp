SRC = main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	Brain.cpp

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -g
OBJS = $(SRC:.cpp=.o)
NAME = smart_animals

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