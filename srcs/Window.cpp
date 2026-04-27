/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:23:46 by afogonca          #+#    #+#             */
/*   Updated: 2026/04/27 15:04:24 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window(void) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    _win = SDL_CreateWindow("a_maze_ing", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
}

Window::~Window() {
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void Window::add_texture(const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        printf("error loading image: %s\n", IMG_GetError());
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(SDL_GetRenderer(_win), surface);
    if (!texture) {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }
    _textures.push_back(texture);
    SDL_FreeSurface(surface);
}