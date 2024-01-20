//
// Created by Maciej Alfut on 04/01/2024.
//


#include "mapTwo.hpp"
using Plat = sf::Sprite;

mapTwo::mapTwo() {

    Plat platform1;
    platform1.setTexture(tl.textureMap["platform"]);
    platform1.setPosition(0.f,350.f);

    Plat platform2 = platform1;
    platform2.setPosition(1060.f,350.f);

    Plat platform3 = platform1;
    platform3.setPosition(440.f,600.f);

    Plat platform4 = platform1;
    platform4.setPosition(640.f,600.f);



    sf::Sprite leftWall;
    leftWall.setTexture(tl.textureMap["leftWall"]);

    sf::Sprite rightWall;
    rightWall.setTexture(tl.textureMap["rightWall"]);
    rightWall.setPosition(1260.f, 0.f);

    sf::Sprite floor;
    floor.setTexture(tl.textureMap["floor"]);
    floor.setPosition(0.f, 700.f);


    sf::Sprite celing;
    celing.setTexture(tl.textureMap["celing"]);

    platforms = {platform1,platform2,platform3,platform4,leftWall, rightWall, floor, celing };

    nextLevel.setPosition(-50.f,50.f);
//    nextLevel.setPosition(1180.f, 620.f);

    enemies = {new WalkingEnemy(10.f,300.f), new WalkingEnemy(1100.f,300.f)};




}

Key mapTwo::getKey()  {
    return key;
}

Portal mapTwo::getNextLevel()  {
    return nextLevel;
}

std::vector<sf::Sprite> mapTwo::getPlatforms()   {
    return platforms;
}
bool mapTwo::hasKey() {
    return false;
}

int mapTwo::whichMap() {
    return 2;
}

void mapTwo::handleKey() {
    key.setPosition(3000.f, 3000.f);
}

void mapTwo::openDoors() {
    platforms[platforms.size()-1].move(sf::Vector2f(0.f, 120.f));
}

void mapTwo::handleEnemies() {
    for (auto enemyIterator = enemies.begin(); enemyIterator != enemies.end();) {
        if (!(*enemyIterator)->isAlive()) {
            delete *enemyIterator;
            enemyIterator = enemies.erase(enemyIterator);
        } else {
            ++enemyIterator;
        }
    }
}

std::vector<Enemy*> mapTwo::getEnemies() {
    return enemies;
}

bool mapTwo::hasEnemies() {
    return true;
}

void mapTwo::updateEnemies(Player& player, sf::Time timeStep) {
    for (auto enemy : enemies) {
        enemy->update(timeStep.asSeconds(), player.getPosition());
    }
}

void mapTwo::reset() {
//    sf::Clock delay;
//
//    enemies.push_back(new WalkingEnemy(10.f,300.f));
//    enemies.push_back(new WalkingEnemy(1100.f,300.f));
//    nextLevel.setPosition(-50.f,50.f);

}

void mapTwo::enableKey() {}

void mapTwo::enableNextLevel() {
    nextLevel.setPosition(1180.f, 620.f);
}


