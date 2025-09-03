#pragma once

#include <SFML/Graphics.hpp>

class Object
{
public:
    sf::Vector2f pos;
    sf::Vector2f scale;
    float speed;

    void spawn(sf::Sprite &asset, sf::RenderWindow &window);
    void update(sf::Sprite &obj, sf::Time &tickrate);
};