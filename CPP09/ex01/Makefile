NAME	 = RPN
C++		 = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC		 = main.cpp RPN.cpp
OBJ		 = $(SRC:.cpp=.o)
HDR		 = RPN.hpp
RM		 = rm -f

all: $(NAME)

%.o: %.cpp $(HDR)
	$(C++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
