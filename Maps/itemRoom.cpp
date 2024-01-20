//
// Created by Maciej Alfut on 20/01/2024.
//

#include "itemRoom.hpp"


using Plat = sf::Sprite;
itemRoom::itemRoom() {

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
}

Key itemRoom::getKey() {
    return Key();
}

Portal itemRoom::getNextLevel() {
    return Portal();
}

std::vector<sf::Sprite> itemRoom::getPlatforms() {
    return platforms;
}

bool itemRoom::hasKey() {
    return false;
}

int itemRoom::whichMap() {
    return 5;
}

void itemRoom::handleKey() {

}

void itemRoom::openDoors() {

}

void itemRoom::handleEnemies() {

}

bool itemRoom::hasEnemies() {
    return false;
}

std::vector<Enemy *> itemRoom::getEnemies() {
    return std::vector<Enemy *>();
}

void itemRoom::updateEnemies(Player &player, sf::Time timeStep) {

}

void itemRoom::reset() {

}

void itemRoom::enableKey() {

}

void itemRoom::enableNextLevel() {

}
