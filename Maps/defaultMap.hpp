//
// Created by Maciej Alfut on 31/12/2023.
//

#ifndef SFMLTEST_DEFAULTMAP_HPP
#define SFMLTEST_DEFAULTMAP_HPP
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Player/Player.hpp"
#include "Enemies/Enemy.hpp"
#include "Key.hpp"
#include "Portal.hpp"

class defaultMap {

public:
    defaultMap();

    virtual Key getKey() = 0 ;

    virtual Portal getNextLevel() = 0 ;

    virtual std::vector<sf::Sprite> getPlatforms() = 0 ;

    virtual  bool hasKey() = 0;

    virtual int whichMap() = 0;

    virtual void handleKey() = 0;

    virtual void openDoors() = 0;

    virtual void handleEnemies() = 0;

    virtual bool hasEnemies() = 0;

    virtual std::vector<Enemy*> getEnemies() = 0;

    virtual void updateEnemies(Player& player, sf::Time timeStep) = 0;

    virtual void reset() = 0;

    virtual void enableKey() = 0;

    virtual void enableNextLevel() = 0;
};


#endif //SFMLTEST_DEFAULTMAP_HPP
