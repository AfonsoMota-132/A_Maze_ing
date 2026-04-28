NAME = a_maze_ing
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11	-fsanitize=leak -g
GLFLAGS = -lGL -lGLU -lglfw

OBJS = $(SRCS:.cpp=.o)
SRCS = $(addprefix srcs/, main.cpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(GLFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f gdb

re: fclean all

.PHONY: all clean fclean re