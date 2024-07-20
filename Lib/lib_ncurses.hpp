/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** lib_ncurses
*/

#include "../ILib.hpp"
#include <ncurses.h>


#ifndef LIB_NCURSES_HPP_
#define LIB_NCURSES_HPP_

class Ncurses : public ILib {
    public:
        Ncurses();
        ~Ncurses();
        void createWindow();
        void closeWindow();
        std::string drawAll(std::vector<std::shared_ptr<Entity>> entities);
        std::string getName();
    protected:
    private:
};


#endif /* !LIB_NCURSES_HPP_ */
