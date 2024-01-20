#include "Player.hpp"

Player::Player() {
    damage = 20;
    health = 100;
    magazineCapacity = 4;
    isShootingLeft = false;
    isShootingRight = false;
    setTexture(tl.textureMap["playerRight"]);
    setPosition(640.f, 600.f);
    playerSpeed = 500.f;
    jumpingHeight = 500.f;
    gravity = 750.f;
    isJumping = false;
    bulletSpeed = 600.f;
}
//obsługa inputów z klawiatury
void Player::inputHandler() {
    goingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    goingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    //obsługa strzelania oraz mechanizmu magazynku
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isShootingRight && magazine < magazineCapacity){
        isShootingRight = true;
        shotRight();
        setTexture(tl.textureMap["playerRight"]);
        fmt::println("prawo {}", rightShots.size());
        magazine++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isShootingLeft && magazine < magazineCapacity){
        isShootingLeft = true;
        setTexture(tl.textureMap["playerLeft"]);

        shotLeft();
        fmt::println("lewo {}", leftShots.size());
        magazine++;
        fmt::print("{}",magazine);

    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        isShootingRight = false;
    }


    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        isShootingLeft = false;
    }
    //Reload
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && magazine == magazineCapacity ){
        magazine = 0;
    }
    //obsługa mechanizmu skakania
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        velocity.y = -jumpingHeight;
        jumpStartPosition = getPosition().y;
        isJumping = true;
    }
}

void Player::update(sf::Time timeStep) {
    //poruszanie się w osi x ustawione na 0 aby gracz bez żadnego inputu nie poruszał się
    velocity.x = 0.f;
    //obsługa ruchu pocisków
    for (auto &bulletRight : rightShots) {
        bulletRight.move(bulletSpeed * timeStep.asSeconds(), 0.f);
    }
    for (auto &bulletLeft : leftShots) {
        bulletLeft.move(-bulletSpeed * timeStep.asSeconds(), 0.f);
    }
    //obsluga i zmiana tekstury gracza podczas poruszania się
    if (goingLeft) {
        velocity.x -= playerSpeed;
        setTexture(tl.textureMap["playerLeft"]);
    }
    if (goingRight) {
        velocity.x += playerSpeed;
        setTexture(tl.textureMap["playerRight"]);
    }
    //obsługa skakania
    if (isJumping) {
        velocity.y += gravity * timeStep.asSeconds();

        // sprawdzanie czy gracz przekroczył maksymalną wysokość skoku
        if (getPosition().y < jumpStartPosition - jumpingHeight) {
            //zatrzymywanie ruchu jeżeli gracz przekroczył wysokość
            velocity.y = 0.f;
            isJumping = false;
        }
    } else {
        velocity.y = gravity/2;

    }
    //grawitacja oddziałująca cały czas na gracza (jest podzielona na 2 ponieważ taka grawitacja w grze najbardziej mi odpowiadała)
    //na koniec faktyczne przesuięcie gracza o wektor pomnożony przez czas aby zgrać z frameratem w gameloopie
    move(velocity * timeStep.asSeconds());
}
//sprawdzanie kolizji gracza
void Player::checkCollision(sf::Sprite &obstacle) {
    const sf::FloatRect characterBounds = this->getGlobalBounds();
    const sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();

    //nie ma kolizji - nic nie robi
    if (!characterBounds.intersects(obstacleBounds)) {
        return;
    }

    float offsetX, offsetY;

    // kalkuluje wartość którą trzeba przesunąć gracza aby nie dotykał obiektów
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

    //kolizja boczna
    if (offsetX < offsetY) {
        velocity.x = 0.f;  //stopowanie
        move((characterBounds.left < obstacleBounds.left) ? -offsetX : offsetX, 0.0f);
    }
        //kolizje góra/dół
    else {
        if (characterBounds.top < obstacleBounds.top) {
            // kolizja z podłogą i umożliwienie skakania
            move(0.0f, -offsetY);
            isJumping = false;
        } else {
            // kolizja z sufitem
            move(0.0f, offsetY);
        }
    }
}

//strzelanie lewo/praweo - analogicznie dodawanie kolejnych bulletów do odpowiednich list
void Player::shotLeft() {
    leftShots.push_back(Bullet(getPosition()));
}

void Player::shotRight() {
    rightShots.push_back(Bullet(getPosition()));

}
//kolizja strzałów - kiedy dotknie przeszkody - usuwa się
void Player::bulletCollion(sf::Sprite &obstacle) {
    for (int i = 0; i < leftShots.size(); i++) {
        if (leftShots[i].getGlobalBounds().intersects(obstacle.getGlobalBounds())){
            leftShots.erase(leftShots.begin() + i);
        }
    }
    for (int i = 0; i < rightShots.size(); i++) {
        if (rightShots[i].getGlobalBounds().intersects(obstacle.getGlobalBounds())){
            rightShots.erase(rightShots.begin() + i);
        }
    }
}






