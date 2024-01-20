#ifndef SFMLTEST_WALKINGENEMY_HPP
#define SFMLTEST_WALKINGENEMY_HPP

#include "Enemy.hpp"
#include "../../Player/TextureLoader.hpp"

class WalkingEnemy : public Enemy {
    TextureLoader tl;

public:
    WalkingEnemy(float x, float y);
    void update(float deltaTime, sf::Vector2f playerPosition) override;
    void onBulletHit(int damage) override;
    bool isAlive() const override;
    void followPlayer(sf::Vector2f playerPosition) override;
    void checkCollisiion(sf::Sprite& obstacle);
private:
    bool alive;
};

#endif //SFMLTEST_WALKINGENEMY_HPP
