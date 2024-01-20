//
// Created by Maciej Alfut on 31/12/2023.
//

#ifndef SFMLTEST_MAPONE_HPP
#define SFMLTEST_MAPONE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../defaultMap.hpp"
#include "../../Player/TextureLoader.hpp"
#include "../Key.hpp"


class mapOne : public defaultMap{
public:
    TextureLoader tl;
    defaultMap* frame;
    mapOne();
    Key key;
    Portal nextLevel;
    sf::Sprite door;
    std::vector<sf::Sprite> platforms;
    Key getKey()  override;
    Portal getNextLevel()  override;
    std::vector<sf::Sprite> getPlatforms() override;
    bool hasKey() override;
    int whichMap() override;
    void handleKey() override;
    void openDoors() override;
    void handleEnemies() override;
    std::vector<Enemy*> getEnemies() override;
     bool hasEnemies() override;
    void updateEnemies(Player& player, sf::Time timeStep) override;
    void reset() override;
    void enableKey() override;
    void enableNextLevel() override;

};


#endif //SFMLTEST_MAPONE_HPP
