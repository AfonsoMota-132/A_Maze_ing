/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Maze.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:38:48 by afogonca          #+#    #+#             */
/*   Updated: 2026/04/27 14:44:30 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Maze.hpp"

Maze::Maze(size_t width, size_t height,
		std::pair<size_t, size_t> entry,
		std::pair<size_t, size_t> exit,
		std::string out_file,
		bool perfect) :
	_width(width), _height(height), _entry(entry),
	_exit(exit), _out_file(out_file), _perfect(perfect),
	_win() {
	_maze = new std::vector<int8_t>(width * height, 0)	;
};

Maze::~Maze(void) {
	delete _maze;
};

void	Maze::loop(void) {
	SDL_Event event;
	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
};

std::ostream &operator<<(std::ostream &out, const Maze &maze) {
	out << "Width: " << maze.get_width()
		<< "\tHeight: " << maze.get_height() << std::endl;
	return out;
}
