NAME = violence
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp \
	  HumanA.cpp \
	  HumanB.cpp \
	  Weapon.cpp
OBJ = ${SRC:.cpp=.o}
CPP = c++
RM = rm -f

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
	
all: $(NAME)
clean:
	$(RM) $(OBJ)	
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all re fclean clean
