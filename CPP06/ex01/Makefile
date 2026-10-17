NAME = serializer
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRC = main.cpp Serializer.cpp Data.cpp
OBJ = $(SRC:.cpp=.o)

all:$(NAME)

%.o:%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS)  $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
re: fclean all