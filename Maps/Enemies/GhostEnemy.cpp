//
// Created by Maciej Alfut on 20/01/2024.
//

#include "GhostEnemy.hpp"

GhostEnemy::GhostEnemy(float x, float y) {
    setTexture(tl.textureMap["ghost"]);
    setPosition(x, y);
    health = 50;
    movementSpeed = 100;
    alive = true;
}

void GhostEnemy::update(float deltaTime, sf::Vector2f playerPosition) {
    if (!isAlive()) return;
    else {
        followPlayer(playerPosition);
        move(velocity * deltaTime);
    }
}

void GhostEnemy::onBulletHit(int damage) {
    health -= damage;
    if (health <= 0) {
        alive = false;
    }
}

bool GhostEnemy::isAlive() const {
    return alive;
}
//funkcja followPlayer jest inna niż w walking enemy
//pozyskujemy
void GhostEnemy::followPlayer(sf::Vector2f playerPosition) {
    if (isAlive()){
        //obliczanie wektora kierunkowego
        sf::Vector2f direction = playerPosition - getPosition();
        //obliczanie modułu wektora kierunkowego (algorytm zaczerpnięty z wykładów Pana Filipa)
        float length = std::hypot(direction.x, direction.y);
        if (length != 0 ){
            //skracamy dystans do gracza
            direction /= length;
        }
        velocity = direction * movementSpeed;
    }

}
//tu nic nie implementuje bo to duch i przenika przez ściany
void GhostEnemy::checkCollisiion(sf::Sprite &obstacle) {}
