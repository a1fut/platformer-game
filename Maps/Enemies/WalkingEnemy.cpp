#include "WalkingEnemy.hpp"

WalkingEnemy::WalkingEnemy(float x, float y) {
    setTexture(tl.textureMap["enemyRight"]);//ustawianie tekstury przeciwnika
    setPosition(x, y);//pozycja startowa
    health = 80; //hp oponenta
    movementSpeed = 300; //prędkość oponenta
    alive = true;
}


//generalna funkcja update później przekazywana aby finalnie skończyć we właściwym game loopie
void WalkingEnemy::update(float deltaTime, sf::Vector2f playerPosition) {
    if (!isAlive()) return;
    else{
        followPlayer(playerPosition);
        //Grawitacja dla przeiwnika oraz followowanie przeciwnika
        velocity.y = 750.f/2;
        move(velocity * deltaTime);
    }

}

//funkcja obsługująca poruszanie się za graczem
void WalkingEnemy::followPlayer(sf::Vector2f playerPosition) {
    if (getPosition().x < playerPosition.x) {
        setTexture(tl.textureMap["enemyRight"]);
        velocity.x = movementSpeed;
    } else if (getPosition().x > playerPosition.x) {
        setTexture(tl.textureMap["enemyLeft"]);

        velocity.x = -movementSpeed;
    } else {
        velocity.x = 0;
    }
}

void WalkingEnemy::onBulletHit(int damage) {
    fmt::println("HP przeciwnika {}", health);
    health -= damage; //odejmuje obrażenia
    fmt::println("HP przeciwnika {}", health);
    if (health <= 0) { //jeżeli obrażenia w sumie przekroczą maksymalne zdrowie przeciwnika, hp przeciwnika i tak równa się 0
        alive = false;
    }
}
//zwraca true jeżeli jego hp jest powyżej 0
bool WalkingEnemy::isAlive() const {
    return alive;
}
//kolizje zaimplementowane takie jak w klasie player
void WalkingEnemy::checkCollisiion(sf::Sprite &obstacle) {
    const sf::FloatRect characterBounds = this->getGlobalBounds();
    const sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();

    if (!characterBounds.intersects(obstacleBounds)) {
        return;
    }

    float offsetX, offsetY;

    if (characterBounds.left < obstacleBounds.left) {
        offsetX = characterBounds.left + characterBounds.width - obstacleBounds.left;
    } else {
        offsetX = obstacleBounds.left + obstacleBounds.width - characterBounds.left;
    }

    if (characterBounds.top < obstacleBounds.top) {
        offsetY = characterBounds.top + characterBounds.height - obstacleBounds.top;
    } else {
        offsetY = obstacleBounds.top + obstacleBounds.height - characterBounds.top;
    }

    if (offsetX < offsetY) {
        velocity.x = 0.f;
        move((characterBounds.left < obstacleBounds.left) ? -offsetX : offsetX, 0.0f);
    }
    else {
        if (characterBounds.top < obstacleBounds.top) {
            move(0.0f, -offsetY);
        } else {
            move(0.0f, offsetY);
        }
    }
}
