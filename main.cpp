/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** main
*/

#include "./Core/core.hpp"

int main(int ac, char **av)
{
    core core;
    if (ac != 2)
        return 84;
    core.lobby(av[1]);
}