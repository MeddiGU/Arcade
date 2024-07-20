/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** snake
*/

#include "snake.hpp"

snake::snake()
{
    std::cout << "Snake" << std::endl;
    srand (time(NULL));
}

snake::~snake()
{
}

std::vector<std::shared_ptr<Entity>>& snake::createEntities(std::string player)
{
    int randx = rand() % 30;
    int randy = rand() % 30;
    _entities.push_back(std::make_shared<Entity>(randx * 30, randy * 30, "./Games/snake/apple.png", "A"));
    _entities.push_back(std::make_shared<Entity>(420, 420, "./Games/snake/snakeHead.png", "H"));
    _entities.push_back(std::make_shared<Entity>(420, 450, "./Games/snake/snake.png", "S"));
    _entities.push_back(std::make_shared<Entity>(420, 480, "./Games/snake/snake.png", "S"));
    _entities.push_back(std::make_shared<Entity>(420, 510, "./Games/snake/snake.png", "S"));
    _score = 0;
    _player = player;

    return _entities;
}

std::vector<std::shared_ptr<Entity>>& snake::updateEntities(std::string key)
{
    _score += 10;
    for (int i = _entities.size() - 1; i > 1; i--){
        _entities[i]->_x = _entities[i - 1]->_x;
        _entities[i]->_y = _entities[i - 1]->_y;
    }
    if (key == "Z") {
        _entities[1]->_y -= 30;
        _entities[1]->_angle = 0;
    }
    if (key == "S") {
        _entities[1]->_y += 30;
        _entities[1]->_angle = 0;
    }
    if (key == "Q") {
        _entities[1]->_x -= 30;
        _entities[1]->_angle = 90;
    }
    if (key == "D") {
        _entities[1]->_x += 30;
        _entities[1]->_angle = 90;
    }
    collision();
    eatApple();
    return _entities;
}

void snake::collision()
{
    for (int i = 2; i < _entities.size(); i++) {
        if (_entities[1]->_x == _entities[i]->_x && _entities[1]->_y == _entities[i]->_y) {
            int lastScore = 0;
            readFile >> lastScore;
            readFile.close();
            if (_score > lastScore){
                std::ofstream file = std::ofstream("assets/scoreSnake", std::ios::trunc);
                file << _player.substr(13);
                file << " ";
                file << _score;
            }
            exit(0);
        }
    }
    if (_entities[1]->_x < 0 || _entities[1]->_x > 870 || _entities[1]->_y < 0 || _entities[1]->_y > 870) {
        std::cout << "You lost" << std::endl;
        int lastScore = 0;
        readFile >> lastScore;
        readFile.close();
        if (_score > lastScore){
            std::ofstream file = std::ofstream("assets/scoreSnake", std::ios::trunc);
            file << _player.substr(13);
            file << " ";
            file << _score;
        }
        exit(0);
    }

}

void snake::eatApple()
{
    if (_entities[0]->_x == _entities[1]->_x && _entities[0]->_y == _entities[1]->_y) {
        int randx = rand() % 30;
        int randy = rand() % 30;
        _entities[0]->_x = randx * 30;
        _entities[0]->_y = randy * 30;
        _entities.push_back(std::make_shared<Entity>(_entities[_entities.size() - 1]->_x, _entities[_entities.size() - 1]->_y, "./Games/snake/snake.png", "S"));
    }
}

std::string snake::getName()
{
    return "snake";
}

extern "C" IGame *createGame()
{
    return new snake();
}
