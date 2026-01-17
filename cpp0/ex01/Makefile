SRC = PhoneBook.cpp \
	Contact.cpp \
	main.cpp

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJS = $(SRC:.cpp=.o)
NAME = phonebook

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

.PHONY: all clean fclean all
