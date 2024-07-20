/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** lib_sfml
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../ILib.hpp"
#include <vector>
#include <string>


#ifndef LIB_SFML_HPP_
#define LIB_SFML_HPP_

class lib_sfml : public ILib {
    public:
        lib_sfml();
        ~lib_sfml();
        void createWindow();
        void closeWindow();
        std::string drawAll(std::vector<std::shared_ptr<Entity>> entities);
        std::string getName();
    protected:
        sf::RenderWindow _window;
};


#endif /* !LIB_SFML_HPP_ */
