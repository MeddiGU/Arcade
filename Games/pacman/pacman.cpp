/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** pacman
*/

#include "pacman.hpp"

pacman::pacman()
{
    std::cout << "Pacman" << std::endl;
    srand(time(NULL));

}

pacman::~pacman()
{
}

void pacman::initWalls()
{
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 29; j++) {
            if (_map[i][j] == '#') {
                _entities.push_back(std::make_shared<Entity>(j * 30, i * 30, "./Games/pacman/wall.png", "#"));
            }
            if (_map[i][j] == '.') {
                _entities.push_back(std::make_shared<Entity>(j * 30 + 12, i * 30 + 12, "./Games/pacman/dot.png", "*", 6, 6));
            }
            if (_map[i][j] == 'O') {
                _entities.push_back(std::make_shared<Entity>(j * 30 + 11, i * 30 + 11, "./Games/pacman/bigDot.png", "O", 8, 8));
            }
        }
    }
}

std::vector<std::shared_ptr<Entity>> &pacman::createEntities(std::string player)
{
    _entities.push_back(std::make_shared<Entity>(420, 510, "./Games/pacman/pacman.png", "P"));
    _entities.push_back(std::make_shared<Entity>(420, 450, "./Games/pacman/ghost.png", "G"));
    _entities.push_back(std::make_shared<Entity>(420, 420, "./Games/pacman/ghost.png", "G"));
    _entities.push_back(std::make_shared<Entity>(390, 450, "./Games/pacman/ghost.png", "G"));
    _entities.push_back(std::make_shared<Entity>(390, 420, "./Games/pacman/ghost.png", "G"));
    initWalls();
    _player = player;
    _score = 0;

    return _entities;
}

void pacman::collisions()
{
    for (int i = 1; i < 5; i++) {
        if (_entities[i]->_x == _entities[0]->_x && _entities[i]->_y == _entities[0]->_y) {
            if (_timer > 0){
                _entities[i]->_x = 450;
                _entities[i]->_y = 450;
                _entities[i]->_path = "./Games/pacman/Eyeghost.png";
            } else {
                std::cout << "You lose" << std::endl;
                int lastScore = 0;
                readFile >> lastScore;
                if (_score > lastScore){
                    std::ofstream file = std::ofstream("assets/scorePacman", std::ios::trunc);
                    file << _player.substr(13);
                    file << " ";
                    file << _score;
                }
                exit(0);
            }
        }
    }
}

void pacman::movePlayer(std::string key)
{
    _score += 10;
    if (key == "Z" && _map [_entities[0]->_y / 30 - 1][_entities[0]->_x / 30] != '#') {
        _entities[0]->_y -= 30;
        _entities[0]->_angle = 270;
    } else if (key == "S" && _map [_entities[0]->_y / 30 + 1][_entities[0]->_x / 30] != '#') {
        _entities[0]->_y += 30;
        _entities[0]->_angle = 90;
    } else if (key == "Q" && _map [_entities[0]->_y / 30][_entities[0]->_x / 30 - 1] != '#') {
        _entities[0]->_x -= 30;
        _entities[0]->_angle = 180;
    } else if (key == "D" && _map [_entities[0]->_y / 30][_entities[0]->_x / 30 + 1] != '#') {
        _entities[0]->_x += 30;
        _entities[0]->_angle = 0;
    }
    if (_entities[0]->_x < 0)
        _entities[0]->_x = 840;
    if (_entities[0]->_x > 840)
        _entities[0]->_x = 0;
}

std::vector<std::shared_ptr<Entity>>& pacman::updateEntities(std::string key)
{
    movePlayer(key);
    if (_timer == 0){
        _entities[1]->_path = "./Games/pacman/ghost.png";
        _entities[2]->_path = "./Games/pacman/ghost.png";
        _entities[3]->_path = "./Games/pacman/ghost.png";
        _entities[4]->_path = "./Games/pacman/ghost.png";
    }
    if (_timer > 0){
        _timer--;
    }
    if (_map [_entities[0]->_y / 30][_entities[0]->_x / 30] == '.') {
        for (auto it = _entities.begin() + 1; it != _entities.end();) {
            if (it->get()->_x - 12 == _entities[0]->_x && it->get()->_y - 12 == _entities[0]->_y) {
                it = _entities.erase(it);
            } else {
                it++;
            }
        }
        if (_entities.size() == 527) {
            std::cout << "You win" << std::endl;
            int lastScore = 0;
            readFile >> lastScore;
            if (_score > lastScore){
                std::ofstream file = std::ofstream("assets/scorePacman", std::ios::trunc);
                file << _player.substr(13);
                file << " ";
                file << _score;
            }
            exit(0);
        }
    }
    if (_map [_entities[0]->_y / 30][_entities[0]->_x / 30] == 'O') {
        for (auto it = _entities.begin() + 1; it != _entities.end();) {
            if (it->get()->_x - 11 == _entities[0]->_x && it->get()->_y - 11 == _entities[0]->_y) {
                it = _entities.erase(it);
            } else {
                it++;
            }
        }
        if (_entities.size() == 527) {
            std::cout << "You win" << std::endl;
            int lastScore = 0;
            readFile >> lastScore;
            if (_score > lastScore){
                std::ofstream file = std::ofstream("assets/scorePacman", std::ios::trunc);
                file << _player.substr(13);
                file << " ";
                file << _score;
            }
            exit(0);
        }
        _entities[1]->_path = "./Games/pacman/Blueghost.png";
        _entities[2]->_path = "./Games/pacman/Blueghost.png";
        _entities[3]->_path = "./Games/pacman/Blueghost.png";
        _entities[4]->_path = "./Games/pacman/Blueghost.png";
        _timer = 80;
    }
    collisions();
    moveGhost();
    collisions();
    return _entities;
}

void pacman::moveGhost()
{
    std::vector<int> tmp = _lastGhostMoves;
    int move;

    _lastGhostMoves.clear();
    for (int i = 1; i < 5; i++){
        if (_entities[i]->_x >= 330 && _entities[i]->_x <= 480 &&
        _entities[i]->_y >= 360 && _entities[i]->_y <= 480)
            tmp[i - 1] = 1;
        if (isMovePossible(tmp[i - 1], i)){
            move = tmp[i - 1];
        } else {
            std::vector<int> allMoves;
            if (_map [_entities[i]->_y / 30 - 1][_entities[i]->_x / 30] != '#')
                allMoves.push_back(1);
            if (_map [_entities[i]->_y / 30 + 1][_entities[i]->_x / 30] != '#')
                allMoves.push_back(2);
            if (_map [_entities[i]->_y / 30][_entities[i]->_x / 30 - 1] != '#')
                allMoves.push_back(3);
            if (_map [_entities[i]->_y / 30][_entities[i]->_x / 30 + 1] != '#')
                allMoves.push_back(4);

            move = allMoves[rand() % allMoves.size()];
        }
        applyMoves(move, i);
        _lastGhostMoves.push_back(move);
        if (_entities[i]->_x < 0)
            _entities[i]->_x = 840;
        if (_entities[i]->_x > 840)
            _entities[i]->_x = 0;
    }
}

bool pacman::isMovePossible(int move, int nbEntity)
{
    if (move == 1 && _map [_entities[nbEntity]->_y / 30 - 1][_entities[nbEntity]->_x / 30] != '#')
        return true;
    if (move == 2 && _map [_entities[nbEntity]->_y / 30 + 1][_entities[nbEntity]->_x / 30] != '#')
        return true;
    if (move == 3 && _map [_entities[nbEntity]->_y / 30][_entities[nbEntity]->_x / 30 - 1] != '#')
        return true;
    if (move == 4 && _map [_entities[nbEntity]->_y / 30][_entities[nbEntity]->_x / 30 + 1] != '#')
        return true;
    return false;
}

void pacman::applyMoves(int move_type, int nbEntity)
{
    if(move_type == 1)
        _entities[nbEntity]->_y -= 30;
    if(move_type == 2)
        _entities[nbEntity]->_y += 30;
    if(move_type == 3)
        _entities[nbEntity]->_x -= 30;
    if(move_type == 4)
        _entities[nbEntity]->_x += 30;
}

std::string pacman::getName()
{
    return "pacman";
}

extern "C" IGame *createGame(std::string player)
{
    return new pacman();
}