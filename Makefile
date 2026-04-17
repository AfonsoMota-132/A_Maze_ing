# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 15:20:40 by afogonca          #+#    #+#              #
#    Updated: 2024/12/20 15:27:31 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a_maze_ing
CXX = c++
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

SRCS = $(addprefix srcs/, main.cpp Maze.cpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

gdb:
	$(CXX) $(CXXFLAGS) $(SRCS) -o gdb -g
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f gdb

re: fclean all

.PHONY: all clean fclean re
