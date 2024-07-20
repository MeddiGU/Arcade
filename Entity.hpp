/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** IEntity
*/

#pragma once
#include <string>

class Entity {
    public:
        Entity(int x, int y, std::string path, std::string ncurse_char, int sizex = 30, int sizey = 30, bool selected = false, int angle = 0)
    : _x(x), _y(y), _path(path), _ncurse_char(ncurse_char), _sizex(sizex), _sizey(sizey), _selected(selected), _angle(angle) {}
        ~Entity(){};

        int _x;
        int _y;
        std::string _path;
        std::string _ncurse_char;
        int _sizex;
        int _sizey;
        bool _selected;
        int _angle;

    protected:
    private:
};
