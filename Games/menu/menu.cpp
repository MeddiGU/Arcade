/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** menu
*/

#include "menu.hpp"

gameMenu::gameMenu()
{
    std::cout << "Menu" << std::endl;
    _i = 0;
    _j = 200;
}

gameMenu::~gameMenu()
{
}

std::vector<std::shared_ptr<Entity>>& gameMenu::createEntities(std::string player)
{
    std::string path = "./lib/";
    int i = 0;
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (entry.path() != "./lib/arcade_menu.so"){
            std::string lib = entry.path();
            lib += "  PRESS " + std::to_string(i / 100 + 1);
            _entities.push_back(std::make_shared<Entity>(0, i, lib, lib));
            i += 100;
        }
    }
    _i = i;
    std::ifstream scoreSnake("./assets/scoreSnake");
    std::string ligne;
    std::getline(scoreSnake, ligne);
    _entities.push_back(std::make_shared<Entity>(0, _i, "./lib/Score Snake: " + ligne, "./lib/Score: " + ligne));
    _i = i + 100;

    std::ifstream scorePacman("./assets/scorePacman");
    std::string line;
    std::getline(scorePacman, line);
    _entities.push_back(std::make_shared<Entity>(0, _i, "./lib/Score Pacman: " + line, "./lib/Score: " + line));
    _i += 100;
    _entities.push_back(std::make_shared<Entity>(0, _i, "./lib/player:", "./lib/player:"));
    _player = std::make_shared<Entity>(0, 0, "./lib/player:default", "./lib/player:default");

    return _entities;
}

std::vector<std::shared_ptr<Entity>>& gameMenu::updateEntities(std::string key)
{
    if (key[0] == 124){
        if (_entities[_entities.size() - 1]->_path.size() > 13)
            _entities[_entities.size() - 1]->_path = _entities[_entities.size() - 1]->_path.substr(0, _entities[_entities.size() - 1]->_path.size() - 1);
        return _entities;
    }
    if (key[0] == 92  || key[0] == 17){
        for (int i = 0; i < 2; i++){
            _entities[i]->_selected = false;
            if (_entities[i]->_path.find("./lib/arcade_snake.so") != std::string::npos)
                _entities[i]->_selected = true;
        }
        _libgame = std::make_shared<Entity>(0, 0, "./lib/arcade_snake.so", "./lib/arcade_snake.so");
        return _entities;
    }
    if (key[0] == 93 || key[0] == 18){
        for (int i = 0; i < 2; i++){
            _entities[i]->_selected = false;
            if (_entities[i]->_path.find("./lib/arcade_pacman.so") != std::string::npos)
                _entities[i]->_selected = true;
        }
        _libgame = std::make_shared<Entity>(0, 0, "./lib/arcade_pacman.so", "./lib/arcade_pacman.so");
        return _entities;
    }
    if (key[0] == 94 || key[0] == 19){
        for (int i = 2; i < 5; i++){
            _entities[i]->_selected = false;
            if (_entities[i]->_path.find("./lib/arcade_ncurses.so") != std::string::npos)
                _entities[i]->_selected = true;
        }
        _libgraphic = std::make_shared<Entity>(0, 0, "./lib/arcade_ncurses.so", "./lib/arcade_ncurses.so");
        return _entities;
    }
    if (key[0] == 116 || key[0] == 20){
        for (int i = 2; i < 5; i++){
            _entities[i]->_selected = false;
            if (_entities[i]->_path.find("./lib/arcade_sfml.so") != std::string::npos)
                _entities[i]->_selected = true;
        }
        _libgraphic = std::make_shared<Entity>(0, 0, "./lib/arcade_sfml.so", "./lib/arcade_sfml.so");
        return _entities;
    }
    if (key[0] == 96 || key[0] == 21){
        for (int i = 2; i < 5; i++){
            _entities[i]->_selected = false;
            if (_entities[i]->_path.find("./lib/arcade_sdl2.so") != std::string::npos)
                _entities[i]->_selected = true;
        }
        _libgraphic = std::make_shared<Entity>(0, 0, "./lib/arcade_sdl2.so", "./lib/arcade_sdl2.so");
        return _entities;
    }
    if (key[0] == 123 || key[0] == -19 && _libgame != nullptr && _libgraphic != nullptr){
        _entities.clear();
        _entities.push_back(_libgame);
        _entities.push_back(_libgraphic);
        _entities.push_back(_player);
        return _entities;
    }
    if (key[0] > '9' && key[0] != ' '){
        _entities[_entities.size() - 1]->_path += key[0];
        _player = std::make_shared<Entity>(0, 0, _entities[_entities.size() - 1]->_path, _entities[_entities.size() - 1]->_path);
    }
    return _entities;
}

std::string gameMenu::getName()
{
    return "menu";
}

extern "C" IGame *createGame()
{
    return new gameMenu();
}