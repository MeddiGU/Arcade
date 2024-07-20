/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "Entity.hpp"

class IGame {
    public:
        virtual std::vector<std::shared_ptr<Entity>>& createEntities(std::string player) = 0;
        virtual std::vector<std::shared_ptr<Entity>>& updateEntities(std::string key) = 0;
        virtual std::string getName() = 0;

    protected:
        std::vector<std::shared_ptr<Entity>> _entities;
        std::string _player;
        int _score;
    private:
};

#endif /* !IGAME_HPP_ */
