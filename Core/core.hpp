/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** core
*/

#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "../ILib.hpp"
#include "../DLLoader.hpp"
#include "../IGame.hpp"


#ifndef CORE_HPP_
#define CORE_HPP_

class core {
public:
    core();
    ~core();
    void lobby(std::string lib);
    int checkLib(std::string lib);
    void returnMenu(DLLoader<ILib> &loader, DLLoader<IGame> &loader2);
    void restartGame(DLLoader<ILib> &loader, DLLoader<IGame> &loader2);
    void changeGame(DLLoader<ILib> &loader, DLLoader<IGame> &loader2);
    void changeLib(DLLoader<ILib> &loader, std::vector<std::shared_ptr<Entity>> entities);

private:
    std::string key = "Z";
    std::string lastKey;
    std::vector<std::shared_ptr<Entity>> entities;
    ILib *graphicLib;
    IGame *gameLib;
    std::string player;
};

class LibUnknownException : public std::exception{
    public:
        LibUnknownException() noexcept{};
        const char *what() const noexcept override {return "Lib unknown";};
};


#endif /* !CORE_HPP_ */
