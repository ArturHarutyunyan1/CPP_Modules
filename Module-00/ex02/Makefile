NAME = bank
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = tests.cpp \
      Account.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean