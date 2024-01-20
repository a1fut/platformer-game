//
// Created by Maciej Alfut on 20/01/2024.
//

#ifndef SFMLTEST_PORTAL_HPP
#define SFMLTEST_PORTAL_HPP
#include "SFML/Graphics.hpp"
#include "../Player/TextureLoader.hpp"

class Portal : public sf::Sprite{
    TextureLoader tl;
public:
    Portal();
};


#endif //SFMLTEST_PORTAL_HPP
