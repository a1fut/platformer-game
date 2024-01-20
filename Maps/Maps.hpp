//
// Created by Maciej Alfut on 26/12/2023.
//

#ifndef SFMLTEST_MAPS_HPP
#define SFMLTEST_MAPS_HPP
#include <iostream>
#include <algorithm>
#include <random>
#include "../Player/Player.hpp"
#include <SFML/Graphics.hpp>
#include "MapOne/mapOne.hpp"
#include "MapTwo/mapTwo.hpp"

class Maps{
private:

    std::vector<defaultMap*> maps;
    std::vector<sf::CircleShape> keys;
    mapOne mapFirst;
    std::vector<sf::CircleShape> nextLevels;
    int index;
    int whichMap;
//    bool mapsCompare(std::vector<sf::RectangleShape> map);

public:
    Maps();

    void randomMap();
    defaultMap* currentMap;
    sf::CircleShape currentMapKey;
    sf::CircleShape currentNextLevel;
    void update(Player &player);
};


#endif //SFMLTEST_MAPS_HPP
