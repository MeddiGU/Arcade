/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** ILib
*/

#ifndef ILIB_HPP_
#define ILIB_HPP_

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "Entity.hpp"

class ILib {
    public:
        virtual void createWindow() = 0;
        virtual void closeWindow() = 0;
        virtual std::string drawAll(std::vector<std::shared_ptr<Entity>> entities) = 0;
        virtual std::string getName() = 0;

    protected:
        std::string _key = " ";
    private:
};

#endif /* !ILIB_HPP_ */
