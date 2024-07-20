/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** core
*/

#include "core.hpp"

core::core()
{
}

core::~core()
{
}

void core::restartGame(DLLoader<ILib> &loader, DLLoader<IGame> &loader2)
{
    std::string name = gameLib->getName();
    graphicLib->closeWindow();
    free(graphicLib);
    graphicLib = loader.getInstance("createLib");
    graphicLib->createWindow();
    free(gameLib);
    gameLib = loader2.getInstance("createGame");
    entities = gameLib->createEntities(player);
    graphicLib->drawAll(entities);
    key = "Z";
    lastKey = "Z";
}

void core::returnMenu(DLLoader<ILib> &loader, DLLoader<IGame> &loader2)
{
    graphicLib->closeWindow();
    loader2.setHandle("lib/arcade_menu.so");
    gameLib = loader2.getInstance("createGame");
    entities = gameLib->createEntities(player);
    graphicLib = loader.getInstance("createLib");
    graphicLib->createWindow();
    graphicLib->drawAll(entities);
    key = "Z";
    lastKey = "Z";
}

void core::changeGame(DLLoader<ILib> &loader, DLLoader<IGame> &loader2)
{
    std::string name = gameLib->getName();
    graphicLib->closeWindow();
    free(graphicLib);
    graphicLib = loader.getInstance("createLib");
    graphicLib->createWindow();
    free(gameLib);
    if (name == "snake") {
        loader2.setHandle("lib/arcade_pacman.so");
        gameLib = loader2.getInstance("createGame");
        entities = gameLib->createEntities(player);
        graphicLib->drawAll(entities);
    } else {
        loader2.setHandle("lib/arcade_snake.so");
        gameLib = loader2.getInstance("createGame");
        entities = gameLib->createEntities(player);
        graphicLib->drawAll(entities);
    }
    key = "Z";
    lastKey = "Z";
}

void core::changeLib(DLLoader<ILib> &loader, std::vector<std::shared_ptr<Entity>> entities)
{
    std::string name = graphicLib->getName();
    graphicLib->closeWindow();
    free(graphicLib);
    if (name == "SDL2") {
        loader.setHandle("lib/arcade_ncurses.so");
        graphicLib = loader.getInstance("createLib");
        graphicLib->createWindow();
        graphicLib->drawAll(entities);
    } else if (name == "SFML") {
        loader.setHandle("lib/arcade_sdl2.so");
        graphicLib = loader.getInstance("createLib");
        graphicLib->createWindow();
        graphicLib->drawAll(entities);
    } else {
        loader.setHandle("lib/arcade_sfml.so");
        graphicLib = loader.getInstance("createLib");
        graphicLib->createWindow();
        graphicLib->drawAll(entities);
    }
    key = lastKey;
}

void core::lobby(std::string file)
{
    std::string lib = file;
    if (lib.find("./lib/") == 0) {
        try {
            checkLib(lib);
        } catch (LibUnknownException &e) {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    DLLoader<ILib> loader(lib);
    try {
        graphicLib = loader.getInstance("createLib");
    } catch (LibUnknownException &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    DLLoader<IGame> loader2("./lib/arcade_menu.so");
    try {
        gameLib = loader2.getInstance("createGame");
    } catch (LibUnknownException &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    entities = gameLib->createEntities("player");
    graphicLib->createWindow();

    while(1){
        lastKey = key;
        key = graphicLib->drawAll(entities);
        if (key == " " || key[0] == -33)
            key = lastKey;
        if (key == "M"){
            returnMenu(loader, loader2);
        }
        if (key == "R"){
            restartGame(loader, loader2);
        }
        if (key == "G"){
            changeGame(loader, loader2);
        }
        if (key == "C"){
            changeLib(loader, entities);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        entities = gameLib->updateEntities(key);
        if (key[0] == 123 || key[0] == -19 && entities.size() == 3){
            graphicLib->closeWindow();
            free(graphicLib);
            free(gameLib);
            player = entities[2]->_path;
            loader2.setHandle(entities[0]->_path);
            gameLib = loader2.getInstance("createGame");
            loader.setHandle(entities[1]->_path);
            entities = gameLib->createEntities(player);
            graphicLib = loader.getInstance("createLib");
            graphicLib->createWindow();
            graphicLib->drawAll(entities);
            key = "Z";
        }
    }
}

int core::checkLib(std::string lib)
{
    std::string ncurses = "./lib/arcade_ncurses.so";
    std::string sfml = "./lib/arcade_sfml.so";
    std::string sdl2 = "./lib/arcade_sdl2.so";

    if (lib == ncurses || lib == sfml || lib == sdl2) {
        std::ifstream file(lib);
        if (file.good()) {
            return 0;
        }
        throw LibUnknownException();
    } else {
        throw LibUnknownException();
    }
}