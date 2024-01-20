//
// Created by Maciej Alfut on 20/01/2024.
//

#ifndef SFMLTEST_ITEMS_HPP
#define SFMLTEST_ITEMS_HPP
#include "SFML/Graphics.hpp"
#include "../Player/TextureLoader.hpp"

class Items {
public:
    Items();
private:
    TextureLoader tl;
    sf::Sprite hpUp;
    sf::Sprite ammoUp;
    sf::Sprite highJump;
public:
    std::vector<sf::Sprite> getItems;
};


#endif //SFMLTEST_ITEMS_HPP
