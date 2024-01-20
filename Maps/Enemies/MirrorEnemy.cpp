//
// Created by Maciej Alfut on 07/01/2024.
//

#include "MirrorEnemy.hpp"

MirrorEnemy::MirrorEnemy(sf::Vector2f position){
    setTexture(tl.textureMap["enemyLeft"]);
    setPosition(position.x + 10.f, position.y);
}

void MirrorEnemy::mirrorMoves(sf::Vector2f position) {
    setPosition(position);
}
