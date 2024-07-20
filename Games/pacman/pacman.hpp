/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** pacman
*/

#include "../../IGame.hpp"

#pragma once


class pacman: public IGame {
    public:
        pacman();
        ~pacman();
        std::vector<std::shared_ptr<Entity>>& createEntities(std::string player);
        std::vector<std::shared_ptr<Entity>>& updateEntities(std::string key);
        std::string getName();
        void moveGhost();
        void applyMoves(int move_type, int nbEntity);
        void initWalls();
        void collisions();
        void movePlayer(std::string key);
        bool isMovePossible(int move, int nbEntity);

    protected:
    private:
        int _timer = 0;
        std::vector<int> _lastGhostMoves = {1, 1, 1, 1};
        std::ifstream readFile = std::ifstream("assets/scorePacman");
        char _map[32][31] = {
        "############################"  ,
        "#O...........##...........O#"  ,
        "#.####.#####.##.#####.####.#"  ,
        "#.####.#####.##.#####.####.#"  ,
        "#..........................#"  ,
        "#.####.##.########.##.####.#"  ,
        "#.####.##.########.##.####.#"  ,
        "#......##....##....##......#"  ,
        "######.#####.##.#####.######"  ,
        "######.#####.##.#####.######"  ,
        "######.##          ##.######"  ,
        "######.## ###  ### ##.######"  ,
        "######.## #      # ##.########",
        "      .   #      #   .        ",
        "######.## #      # ##.########",
        "######.## #      # ##.######"  ,
        "######.## ######## ##.######"  ,
        "######.##          ##.######"  ,
        "######.## ######## ##.######"  ,
        "######.## ######## ##.######"  ,
        "#............##............#"  ,
        "#.####.#####.##.#####.####.#"  ,
        "#.####.#####.##.#####.####.#"  ,
        "#...##................##...#"  ,
        "###.##.##.########.##.##.###"  ,
        "###.##.##.########.##.##.###"  ,
        "#......##....##....##......#"  ,
        "#.##########.##.##########.#"  ,
        "#O........................O#"  ,
        "############################"  ,
    };
};

