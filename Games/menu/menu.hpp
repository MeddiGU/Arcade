/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** snake
*/

#include "../../IGame.hpp"
#include <filesystem>

#pragma once

class gameMenu: public IGame {
    public:
        gameMenu();
        ~gameMenu();
        std::vector<std::shared_ptr<Entity>>& createEntities(std::string player);
        std::vector<std::shared_ptr<Entity>>& updateEntities(std::string key);
        std::string getName();

    protected:
    private:
        int _i;
        int _j;
        std::shared_ptr<Entity> _libgraphic;
        std::shared_ptr<Entity> _libgame;
        std::shared_ptr<Entity> _player;
};

