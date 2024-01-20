//
// Created by Maciej Alfut on 07/01/2024.
//

#ifndef SFMLTEST_MIRRORENEMY_HPP
#define SFMLTEST_MIRRORENEMY_HPP
#include "SFML/Graphics.hpp"
#include "../../Player/Player.hpp"
#include "../../Player/TextureLoader.hpp"

class MirrorEnemy : public sf::Sprite{
private:
    TextureLoader tl;
public:
    void mirrorMoves(sf::Vector2f position);
    MirrorEnemy(sf::Vector2f position);

};


#endif //SFMLTEST_MIRRORENEMY_HPP
