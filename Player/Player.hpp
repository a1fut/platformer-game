//
// Created by Maciej Alfut on 12/12/2023.
//

#ifndef SFMLTEST_PLAYER_HPP
#define SFMLTEST_PLAYER_HPP


#include <SFML/Graphics.hpp>
#include "fmt/core.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Bullet.hpp"
#include "TextureLoader.hpp"
#include "../Maps/Enemies/Enemy.hpp"

//inicjalizacja potrzebnych zmiennych oraz metod dla gracza
class Player : public sf::Sprite {
public:
    Player();
    int jumpingHeight;
    std::vector<Bullet> leftShots, rightShots;
    int damage, health;
    sf::Vector2<float> velocity;
    void update(sf::Time timeStep);
    void checkCollision(sf::Sprite &obstacle);
    void inputHandler();
    float gravity, jumpStartPosition, bulletSpeed, playerSpeed;
    sf::Texture sprite;
    void shotLeft();
    void shotRight();
    void bulletCollion(sf::Sprite &obstacle);
    int magazineCapacity;

private:
    TextureLoader tl;
    bool goingRight, goingLeft, isJumping, isShootingLeft, isShootingRight;
    int magazine = 0;
};


#endif //SFMLTEST_PLAYER_HPP
