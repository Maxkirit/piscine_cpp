SRC = main.cpp \
	Zombie.cpp \
	newZombie.cpp \
	randomChump.cpp \

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
OBJS = $(SRC:.cpp=.o)
NAME = zombie

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