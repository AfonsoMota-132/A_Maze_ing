/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:22:40 by afogonca          #+#    #+#             */
/*   Updated: 2026/04/27 14:45:14 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define WIDTH 1280
#define HEIGHT 720

class Window {
private:
    SDL_Window* _win;
    std::vector<SDL_Texture*> _textures;
public:
    Window(void);
    ~Window(void);

    void add_texture(const char* path);
    SDL_Window* get_window() { return _win; }
};