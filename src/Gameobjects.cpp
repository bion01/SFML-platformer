#include <SFML/Graphics.hpp>
#include "gameobjects.hpp"
using namespace sf;


void Object::spawn(Sprite &asset, RenderWindow &window)
{
      //asset.setPosition(pos);
    asset.setScale(scale);
           
    window.draw(asset);
}
void Object::update(Sprite &obj, Time &tickrate)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        obj.move({-speed*tickrate.asSeconds(), 0.0f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        obj.move({speed*tickrate.asSeconds(), 0.0f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        obj.move({0.f, -speed*tickrate.asSeconds()});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        obj.move({0.f, speed*tickrate.asSeconds()});
}
