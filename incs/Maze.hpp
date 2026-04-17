/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Maze.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:28:38 by afogonca          #+#    #+#             */
/*   Updated: 2026/04/17 15:18:31 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>
#include <cstdint>
#include <vector>

class Maze {
private:
	size_t	_width;
	size_t	_height;
	std::pair<size_t, size_t>	_entry;
	std::pair<size_t, size_t>	_exit;
	std::string	_out_file;
	bool		_perfect;
	std::vector<int8_t>	*_maze;
public:
	Maze(size_t width = 10, size_t height = 10,
		std::pair<size_t, size_t> entry = std::pair<size_t, size_t>(0, 0),
		std::pair<size_t, size_t> exit = std::pair<size_t, size_t>(9, 9),
		std::string out_file = "output.txt",
		bool perfect = true);
	~Maze();

	Maze	operator+(const Maze &maze) const {
		return Maze(_width + maze._width, _height + maze._height, _entry, _exit, _out_file, _perfect);
	};

	size_t	get_width(void) { return _width; };
	size_t	get_height(void) { return _height; };
	size_t	get_width(void) const { return _width; };
	size_t	get_height(void) const { return _height; };
};

std::ostream &operator<<(std::ostream &out, const Maze &maze);
