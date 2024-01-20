//
// Created by Maciej Alfut on 20/01/2024.
//

#ifndef SFMLTEST_GHOSTENEMY_HPP
#define SFMLTEST_GHOSTENEMY_HPP


#include "Enemy.hpp"

class GhostEnemy : public Enemy {
    TextureLoader tl;

public:
    GhostEnemy(float x, float y);
    void update(float deltaTime, sf::Vector2f playerPosition) override;
    void onBulletHit(int damage) override;
    bool isAlive() const override;
    void followPlayer(sf::Vector2f playerPosition) override;
    void checkCollisiion(sf::Sprite& obstacle);

private:
    bool alive;
};


#endif //SFMLTEST_GHOSTENEMY_HPP
