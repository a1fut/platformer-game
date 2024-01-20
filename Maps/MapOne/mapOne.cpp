//
// Created by Maciej Alfut on 31/12/2023.
//

#include "mapOne.hpp"
using Plat = sf::Sprite;

mapOne::mapOne() {

    Plat platformOne1;
    platformOne1.setTexture(tl.textureMap["platform"]);
    platformOne1.setPosition(0.f, 600.f);
    Plat platformOne2 = platformOne1;
    platformOne2.setPosition(0.f, 500.f);
    Plat platformOne3 = platformOne1;
    platformOne3.setPosition(500.f, 400.f);
    Plat platformOne4 = platformOne1;
    platformOne4.setPosition(700.f, 300.f);
    Plat platformOne5 = platformOne1;
    platformOne5.setPosition(150.f, 200.f);
    Plat platformOne6 = platformOne1;
    platformOne6.setPosition(1080.f, 600.f);

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

    door.setTexture(tl.textureMap["door"]);
    door.setPosition(1080.f,620.f);
    key.setPosition(250.f, 170.f);
    platforms = {platformOne1, platformOne2,platformOne3, platformOne4, platformOne5, platformOne6,leftWall, rightWall, floor, celing, door};
    nextLevel.setPosition(1180.f, 630.f);
}

Key mapOne::getKey()  {
    return key;
}

Portal mapOne::getNextLevel()  {
    return nextLevel;
}

std::vector<sf::Sprite> mapOne::getPlatforms()   {
    return platforms;
}
bool mapOne::hasKey() {
    return true;
}

int mapOne::whichMap() {
    return 1;
}

void mapOne::handleKey() {
    key.setPosition(3000.f, 3000.f);
}

void mapOne::openDoors() {
    platforms[platforms.size()-1].setPosition(-50.f, 100.f);
}

void mapOne::handleEnemies() {

}

std::vector<Enemy*> mapOne::getEnemies() {
    return std::vector<Enemy*>();
}

bool mapOne::hasEnemies() {
    return false;
}

void mapOne::updateEnemies(Player& player, sf::Time timeStep) {
    //w klasie tej mapy nie występują wrogowie więc funkcja pozostaje pusta
}

void mapOne::reset() {
//    key.setPosition(250.f, 170.f);
//    platforms[platforms.size()-1].move(sf::Vector2f(0.f, -120.f));
}

void mapOne::enableKey() {}

void mapOne::enableNextLevel() {}



