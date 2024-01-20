//
// Created by Maciej Alfut on 07/01/2024.
//

#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position) {
    setPosition(position.x + 20.f, position.y + 20.f);
    setFillColor(sf::Color::Magenta);
    setSize({10.f,5.f});
}
