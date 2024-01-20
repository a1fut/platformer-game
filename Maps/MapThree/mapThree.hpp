//
// Created by Maciej Alfut on 20/01/2024.
//

#ifndef SFMLTEST_MAPTHREE_HPP
#define SFMLTEST_MAPTHREE_HPP


#include "../defaultMap.hpp"
#include "../Enemies/GhostEnemy.hpp"

class mapThree : public defaultMap{
    TextureLoader tl;
    Key getKey()  override;
    Portal getNextLevel()  override;
    std::vector<sf::Sprite> getPlatforms() override;
    bool hasKey() override;
    int whichMap() override;
    void handleKey() override;
    void openDoors() override;
    void handleEnemies() override;
    bool hasEnemies() override;
    std::vector<Enemy*> getEnemies() override;
    void updateEnemies(Player& player, sf::Time timeStep) override;
    void reset() override;
    void enableKey() override;
    void enableNextLevel() override;


public:
    mapThree();


private:
    sf::Clock spawnTimer;
    int seconds = 0;
    Key key;
    Portal nextLevel;
    sf::Sprite door;
    std::vector<sf::Sprite> platforms;
    std::vector<Enemy*> enemies;

};


#endif //SFMLTEST_MAPTHREE_HPP
