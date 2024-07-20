/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** lib_sdl2
*/

#include "lib_sdl2.hpp"

SDL2::SDL2()
{
}

SDL2::~SDL2()
{
}

void SDL2::createWindow()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }
    _window = SDL_CreateWindow("Fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, 0);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void SDL2::closeWindow()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

std::string SDL2::drawAll(std::vector<std::shared_ptr<Entity>> entities)
{
    SDL_RenderClear(_renderer);
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("./assets/SegaSonic.TTF", 20);
    if (font == nullptr){
        closeWindow();
        throw FontException();
    }
    for (auto &entity : entities) {
        if (entity->_path.find("lib") != std::string::npos) {
            SDL_Color textColor = { 200, 100, 10 };
            if (entity->_selected == true)
                textColor = { 255, 0, 0 };
            SDL_Surface* textSurface = TTF_RenderText_Blended(font, entity->_path.substr(6).c_str(), textColor);
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
            SDL_Rect destinationRect = {entity->_x, entity->_y, 500, 100};
            SDL_RenderCopy(_renderer, textTexture, nullptr, &destinationRect);
        } else {
            SDL_Surface* imageSurface = IMG_Load(entity->_path.c_str());
            SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(_renderer, imageSurface);
            SDL_FreeSurface(imageSurface);
            SDL_Rect destinationRect = {entity->_x, entity->_y, entity->_sizex, entity->_sizey};
            SDL_RenderCopyEx(_renderer, imageTexture, nullptr, &destinationRect, entity->_angle, nullptr, SDL_FLIP_NONE);
        }
    }
    SDL_RenderPresent(_renderer);
    for (auto &entity : entities) {
        if (entity->_path.find("lib") != std::string::npos) {
            _key = "   ";
        }
    }
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            closeWindow();
            exit(0);
        }
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                closeWindow();
                exit(0);
            }
            _key[0] = event.key.keysym.sym - 32;
        }
    }
    return _key;
}

std::string SDL2::getName()
{
    return "SDL2";
}

extern "C" ILib *createLib()
{
    return new SDL2();
}


