NAME = a_maze_ing
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -I$(HOME)/.local/include -Iincs
SDLFLAGS = -L$(HOME)/.local/lib -lSDL2 -lSDL2_image -Wl,-rpath,$(HOME)/.local/lib
OBJS = $(SRCS:.cpp=.o)
SRCS = $(addprefix srcs/, main.cpp Maze.cpp Window.cpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(SDLFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f gdb

re: fclean all

.PHONY: all clean fclean re