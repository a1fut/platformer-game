//
// Created by Maciej Alfut on 20/01/2024.
//

#include "mapThree.hpp"
using Plat = sf::Sprite;

mapThree::mapThree() {
    sf::Clock delayTime;

    Plat platform1;
    platform1.setTexture(tl.textureMap["platform"]);
    platform1.setPosition(650.f,300.f);

    Plat platform2 = platform1;
    platform2.setPosition(1060.f,400.f);

    Plat platform3 = platform1;
    platform3.setPosition(440.f,600.f);

    Plat platform4 = platform1;
    platform4.setPosition(640.f,500.f);

    Plat platform5 = platform1;
    platform5.setPosition(0.f, 300.f);

    Plat platform6 = platform1;
    platform6.setPosition(1060.f, 100.f);

    Plat appearingPlatform = platform1;
    appearingPlatform.setPosition(-250.f,40.f);

    key.setPosition(100.f, 260.f);



    sf::Sprite leftWall;
    leftWall.setTexture(tl.textureMap["leftWall"]);

    sf::Sprite rightWall;
    rightWall.setTexture(tl.textureMap["rightWall"]);
    rightWall.setPosition(1260.f, 0.f);

    sf::Sprite floor;
    floor.setTexture(tl.textureMap["floor"]);
    floor.setPosition(0.f, 700.f);
    sf::Sprite floor2;
    floor2 = floor;

    sf::Sprite celing;
    celing.setTexture(tl.textureMap["celing"]);

    platforms = {platform1,platform2,platform3,platform4,platform5,platform6,leftWall, rightWall, floor, celing,appearingPlatform};

//    nextLevel.setPosition(-50.f,50.f);

    nextLevel.setPosition(-50.f,50.f);
    enemies = {new GhostEnemy(20.f,1600.f)};

//    enemies = {new GhostEnemy(20.f,1600.f), new GhostEnemy(1000.f,1600.f), new GhostEnemy(1200.f, 1600.f),new GhostEnemy(100.f, 1600.f),new GhostEnemy(300.f, 1600.f),
//               new GhostEnemy(20.f,0.f), new GhostEnemy(1000.f,0.f), new GhostEnemy(1200.f, 0.f),new GhostEnemy(100.f, 0.f),new GhostEnemy(300.f, 0.f)};
}

Key mapThree::getKey() {
    return key;
}

Portal mapThree::getNextLevel() {
    return nextLevel;
}

std::vector<sf::Sprite> mapThree::getPlatforms() {
    return platforms;
}

bool mapThree::hasKey() {
    return true;
}

int mapThree::whichMap() {
    return 3;
}

void mapThree::handleKey() {
    key.setPosition(-50.f,50.f);
    platforms[platforms.size()-1].setPosition(860.f, 200.f);
}

void mapThree::openDoors() {

}
//tak samo jak w mapTwo
void mapThree::handleEnemies() {

    //usuwanie przeciwników z tabeli po zabiciu
    for (auto enemyIterator = enemies.begin(); enemyIterator != enemies.end();) {
        if (!(*enemyIterator)->isAlive()) {
            delete *enemyIterator;
            enemyIterator = enemies.erase(enemyIterator);
        } else {
            ++enemyIterator;
        }
    }
    //spawnowanie przez 9 sekund przeciwników w losowej pozycji na mapie
    if (seconds <=5){
        if (spawnTimer.getElapsedTime().asSeconds() >= 1) {
            enemies.push_back(new GhostEnemy(rand() % 1000, rand() % 800));
            seconds++;
            spawnTimer.restart();
        }
    }


}

bool mapThree::hasEnemies() {
    return true;
}

std::vector<Enemy *> mapThree::getEnemies() {
    return enemies;
}

void mapThree::updateEnemies(Player &player, sf::Time timeStep) {
    for (auto enemy : enemies) {
        enemy->update(timeStep.asSeconds(), player.getPosition());
    }
}
void mapThree::reset() {
//    handleEnemies();
//    sf::Clock delay;
//    delay.restart();
//        enemies.push_back(new GhostEnemy(20.f,-20.f));
//        seconds = 0;
//    key.setPosition(100.f, 260.f);
//    platforms[platforms.size()-1].setPosition(-250.f,40.f);
}

void mapThree::enableKey() {

}

void mapThree::enableNextLevel() {
        nextLevel.setPosition(1160.f, 40.f);
}
