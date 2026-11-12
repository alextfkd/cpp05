NAME = ex00

CXX = c++ -g

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(addprefix ./, $(SRCS:.cpp=.o))

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

cppformat:
	clang-format -i $(SRCS) *.hpp

cpplint:
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet $(SRCS) *.hpp -- -Wall -Wextra -Werror -std=c++98

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: valgrind
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re cppformat cpplint
