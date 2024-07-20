/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** snake
*/

#include "../../IGame.hpp"

#ifndef SNAKE_HPP_
#define SNAKE_HPP_


class snake: public IGame {
    public:
        snake();
        ~snake();
        std::vector<std::shared_ptr<Entity>>& createEntities(std::string player);
        std::vector<std::shared_ptr<Entity>>& updateEntities(std::string key);
        std::string getName();
        void eatApple();
        void collision();

    protected:
    private:
        std::ifstream readFile = std::ifstream("assets/scoreSnake");
};

#endif /* !SNAKE_HPP_ */
