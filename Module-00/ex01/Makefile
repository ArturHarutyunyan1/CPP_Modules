NAME = phonebook
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = src/main.cpp \
	  src/utils.cpp \
      src/Contact.cpp \
	  src/PhoneBook.cpp
OBJ = ${SRC:.cpp=.o}
CC = c++
RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all re fclean clean