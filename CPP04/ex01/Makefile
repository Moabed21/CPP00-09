NAME	 = Zoo
C++		 = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC		 = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
RM  = rm -f

all: $(NAME)

%.o: %.cpp
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
