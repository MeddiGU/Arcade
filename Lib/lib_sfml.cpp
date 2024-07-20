/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-meddi.gueran
** File description:
** lib_sfml
*/

#include "lib_sfml.hpp"

lib_sfml::lib_sfml()
{
}

lib_sfml::~lib_sfml()
{
}

std::string lib_sfml::drawAll(std::vector<std::shared_ptr<Entity>> entities)
{
    _window.clear();
    for (auto &entity : entities) {
        if (entity->_path.find("lib") != std::string::npos) {
            sf::Text text;
            sf::Font font;
            font.loadFromFile("assets/SegaSonic.TTF");
            text.setFont(font);
            text.setString(entity->_path.substr(6));
            text.setCharacterSize(24);
            if (entity->_selected == true)
                text.setFillColor(sf::Color::Red);
            else
                text.setFillColor(sf::Color::White);
            text.setPosition(entity->_x, entity->_y);
            _window.draw(text);
        } else {
            sf::Texture texture;
            texture.loadFromFile(entity->_path);
            sf::Sprite sprite(texture);
            sprite.setOrigin(entity->_sizex / 2, entity->_sizey / 2);
            sprite.setRotation(entity->_angle);
            sprite.setPosition(entity->_x + entity->_sizex / 2, entity->_y + entity->_sizey / 2);
            _window.draw(sprite);
        }
    }
    for (auto &entity : entities) {
        if (entity->_path.find("lib") != std::string::npos) {
            _key = "   ";
        }
    }
    _window.display();
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            _window.close();
            exit(0);
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape){
                _window.close();
                exit(0);
            }
            _key[0] = event.key.code + 65;
        }
    }
    return _key;
}

std::string lib_sfml::getName()
{
    return "SFML";
}

void lib_sfml::createWindow()
{
    _window.create(sf::VideoMode(900, 900), "SFML window");
}

void lib_sfml::closeWindow()
{
    _window.close();
}

extern "C" ILib *createLib()
{
    return new lib_sfml();
}
