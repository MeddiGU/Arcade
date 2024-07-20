/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** lib_ncurses
*/

#include "lib_ncurses.hpp"
#include <fstream>

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses()
{
}

void Ncurses::createWindow()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

std::string Ncurses::getName()
{
    return "Ncurses";
}

void Ncurses::closeWindow()
{
    clear();
    endwin();
}

std::string Ncurses::drawAll(std::vector<std::shared_ptr<Entity>> entities)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    clear();
    for (int i = 0; i < 30; i++){
        mvprintw(i, 30, "|");
    }
    for (int i = 0; i < 30; i++){
        mvprintw(30, i, "|");
    }
    for (auto &entity : entities) {
        if (entity->_path.find("lib") != std::string::npos) {
            if (entity->_selected == true)
                attron(A_REVERSE);
            mvprintw(entity->_y / 30, entity->_x / 50, entity->_path.substr(6).c_str());
            attroff(A_REVERSE);
        } else {
            if (entity->_path == "./Games/snake/snake.png" || entity->_path == "./Games/snake/snakeHead.png"){
                attron(COLOR_PAIR(2));
            } else if (entity->_path == "./Games/snake/apple.png" || entity->_path == "./Games/pacman/ghost.png"){
                attron(COLOR_PAIR(1));
            } else if (entity->_path == "./Games/pacman/pacman.png"){
                attron(COLOR_PAIR(3));
            } else if (entity->_path == "./Games/pacman/Blueghost.png"){
                attron(COLOR_PAIR(4));
            }
            mvprintw(entity->_y / 30, entity->_x / 30, entity->_ncurse_char.c_str());
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
        }
    }
    for (auto &entity : entities) {
        if (entity->_path.find("lib") != std::string::npos) {
            _key = "   ";
        }
    }
    int key = getch();
    if (key == 27) {
        clear();
        endwin();
        exit(0);
    }
    if (key != -1){
        _key[0] = key - 32;
    }
    if (key == '&'){
        _key[0] = 17;
    }
    if (key == 195 || key == 169){
        _key[0] = 18;
    }
    if (key == '"'){
        _key[0] = 19;
    }
    if (key == '\''){
        _key[0] = 20;
    }
    if (key == '('){
        _key[0] = 21;
    }
    if (key == '\n'){
        _key[0] = -19;
    }
    if (key == 263){
        _key[0] = 124;
    }
    refresh();
    return _key;
}

extern "C" ILib *createLib()
{
    return new Ncurses();
}