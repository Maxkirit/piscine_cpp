SRC = main.cpp

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
NAME = BRAIN
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re