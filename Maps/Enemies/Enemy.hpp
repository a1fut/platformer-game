//
// Created by Maciej Alfut on 18/01/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "../../Player/Player.hpp"
//Pierwotna klasa dla każdego przeciwnika
class Enemy : public sf::Sprite {
public:
    Enemy() = default;

    virtual void update(float deltaTime,sf::Vector2f playerPosition) = 0;
    virtual void onBulletHit(int damage) = 0;
    virtual bool isAlive() const = 0;
    virtual void followPlayer(sf::Vector2f playerPosition) = 0;
    virtual void checkCollisiion(sf::Sprite& obstacle) = 0;

protected:
    float health;
    float damage;
    float movementSpeed;
    sf::Vector2f velocity;
};

#endif //SFMLTEST_ENEMY_HPP
