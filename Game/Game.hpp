//
// Created by Maciej Alfut on 02/12/2023.
//

#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP
#include <SFML/Graphics.hpp>
#include "fmt/core.h"
#include "../Player/Player.hpp"
#include "../Maps/Maps.hpp"
#include "../Player/TextureLoader.hpp"

class Game {

public:
    Game();
    void    run();
    sf::RenderWindow gameWindow = sf::RenderWindow(sf::VideoMode(1280,720), "Game");
    sf::Sprite background;
    Maps maps;
    void    menu();
    enum State{
        PLAYING,
        MENU
    };




private:
    sf::Text health;
    State state;
    sf::Font font;
    TextureLoader tl;
    Player player;
    void eventHandler(), update(sf::Time timeStep), render();
    sf::Time timePerFrame;
    sf::RectangleShape floor;
    sf::RectangleShape floor2;
    void checkBulletEnemyCollision();
};


#endif //SFMLTEST_GAME_HPP
