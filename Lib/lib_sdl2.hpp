/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** lib_sdl2
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../ILib.hpp"


#ifndef LIB_SDL2_HPP_
#define LIB_SDL2_HPP_


class SDL2 : public ILib {
    public:
        SDL2();
        ~SDL2();
        void createWindow();
        void closeWindow();
        std::string drawAll(std::vector<std::shared_ptr<Entity>> entities);
        std::string getName();
    protected:
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};

class FontException : public std::exception{
    public:
        FontException() noexcept{};
        const char *what() const noexcept override {return "Unable to load font";};
};

#endif /* !LIB_SDL2_HPP_ */
