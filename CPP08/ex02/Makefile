NAME	 = abomination
C++		 = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC		 = main.cpp
OBJ = $(SRC:.cpp=.o)
RM  = rm -f

all: $(NAME)

%.o: %.cpp
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ) MutantStack.hpp
	$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
