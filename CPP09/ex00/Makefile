NAME	 = btc
C++		 = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC		 = main.cpp BitcoinExchange.cpp
OBJ		 = $(SRC:.cpp=.o)
HDR		 = BitcoinExchange.hpp
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
