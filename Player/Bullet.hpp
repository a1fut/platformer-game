//
// Created by Maciej Alfut on 07/01/2024.
//

#ifndef SFMLTEST_BULLET_HPP
#define SFMLTEST_BULLET_HPP
#include "SFML/Graphics.hpp"


class Bullet : public sf::RectangleShape {
public:
    //Daję w konstruktorze domyślną pustą pozycję
    Bullet(sf::Vector2f position = {});
};


#endif //SFMLTEST_BULLET_HPP
