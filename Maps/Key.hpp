//
// Created by Maciej Alfut on 20/01/2024.
//

#ifndef SFMLTEST_KEY_HPP
#define SFMLTEST_KEY_HPP
#include "SFML/Graphics.hpp"
#include "../Player/TextureLoader.hpp"

class Key : public sf::Sprite{
    TextureLoader tl;
public:
    Key();
};


#endif //SFMLTEST_KEY_HPP
