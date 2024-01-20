//
// Created by Maciej Alfut on 04/01/2024.
//

#ifndef SFMLTEST_MAPTWO_HPP
#define SFMLTEST_MAPTWO_HPP
#include <SFML/Graphics.hpp>
#include "../defaultMap.hpp"
#include "../../Player/Player.hpp"
#include "../../Player/TextureLoader.hpp"
#include "../Enemies/WalkingEnemy.hpp"



class mapTwo : public defaultMap{
public:
    mapTwo();
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





private:
    Key key;
    Portal nextLevel;
    sf::Sprite door;
    std::vector<sf::Sprite> platforms;
    std::vector<Enemy*> enemies;

};


#endif //SFMLTEST_MAPTWO_HPP
