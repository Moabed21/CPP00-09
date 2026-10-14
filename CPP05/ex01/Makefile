NAME= 		Bureaucrat
SRCS=		Bureaucrat.cpp main.cpp Form.cpp
OBJS=		$(SRCS:.cpp=.o)
RM= 		rm -f
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all