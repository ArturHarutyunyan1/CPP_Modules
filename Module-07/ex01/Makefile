NAME = iter
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
CPP = c++
RM = rm -f

$(NAME): $(OBJ) iter.hpp
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all re fclean clean
