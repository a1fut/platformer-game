//
// Created by Maciej Alfut on 02/12/2023.
//

#include "Game.hpp"

//Constructor
Game::Game() {
    background.setTexture(tl.textureMap["background"]);
    maps.randomMap();
    //menu również nie zdążyłem zaimplementować
//    state = MENU;
//    health.setFont(tl.fontMap["font"]);
//    health.setCharacterSize(24);
    health.setPosition(100,100);
    health.setFillColor(sf::Color::White);
}

//Game loop
void Game::run() {
    //game loop oparty o restartujący się zegar tak aby
    //utrzymać w miarę stały framerate
    sf::Clock clock;
    sf::Clock dmgClock;
    while (gameWindow.isOpen()){
//        switch (state) {
//            case MENU:
//                menu();
//                break;
//            case PLAYING:
                sf::Time timeStep = clock.restart();
                eventHandler();
                player.inputHandler();
                player.update(timeStep);
                maps.update(player);

//                fmt::println("{}",maps.currentMap->getEnemies().size());
                for (auto enemy : maps.currentMap->getEnemies()) {
                    enemy->update(timeStep.asSeconds(), player.getPosition());
                    if (enemy->getGlobalBounds().intersects(player.getGlobalBounds())){
                        if (dmgClock.getElapsedTime().asSeconds() >= 1){
                            player.health -= 20;
                            fmt::println("HP {}", player.health);
                            dmgClock.restart();
                        }
                    }
                }
                render();
        }

//    }
}


//funkcja sprawdzająca kolizję przeciwnika z bulletem
void Game::checkBulletEnemyCollision() {
    //iteruje po wszystkich przeciwnikach danej mapy (referencja na wroga aby działać na oryginale)
    for (auto& enemy : maps.currentMap->getEnemies()) {
        //teraz po kazdym bullecie z tych wystrzelonych w lewo
        for (auto bulletIt = player.leftShots.begin(); bulletIt != player.leftShots.end();) {
            //sprawdzam czy się dotykają bullety i przeciwnicy ze sobą
            if (bulletIt->getGlobalBounds().intersects(enemy->getGlobalBounds())) {
                //wykonuje obsługę postrzału przeciwnika i wymazuje ten bullet
                enemy->onBulletHit(player.damage);
                bulletIt = player.leftShots.erase(bulletIt);
            } else {
                //przesówam iterator dalej
                ++bulletIt;
            }
        }
        //adekwatnie jak u góry
        for (auto bulletIt = player.rightShots.begin(); bulletIt != player.rightShots.end();) {
            if (bulletIt->getGlobalBounds().intersects(enemy->getGlobalBounds())) {
                enemy->onBulletHit(player.damage);
                bulletIt = player.rightShots.erase(bulletIt);
            } else {
                ++bulletIt;
            }
        }
    }
}





//Obsługa inputu gracza (okno)
void Game::eventHandler() {
    sf::Event event;
    while (gameWindow.pollEvent(event)){
        switch (event.type){
            default:
                break;
            case sf::Event::Closed:
                gameWindow.close();
                break;
        }
    }
}

//renderowanie wszystkich elementów potrzebnych na ekranie
void Game::render() {
//        health.setString(std::to_string(player.health));
//        gameWindow.draw(health);
    if (player.health > 0) {
        gameWindow.clear(sf::Color::White);
        gameWindow.draw(background);
        gameWindow.draw(player);
        if (player.rightShots.size() > 0) {
            for (auto bullet: player.rightShots) {
                gameWindow.draw(bullet);
            }
        }
        if (player.leftShots.size() > 0) {
            for (auto bullet: player.leftShots) {
                gameWindow.draw(bullet);
            }
        }
        //sprawdzanie czy poziom ma przeciwników
        //jeżeli tak to ich rysuję o ile nie są martwi
        if (maps.currentMap->hasEnemies()) {
            for (int i = 0; i < maps.currentMap->getEnemies().size(); i++) {
                if (maps.currentMap->getEnemies()[i]->isAlive()) {
                    //wskaźnik ponieważ odwołuję się do obiektu Enemy który jest jedynie rodzicem i posiada same anonimowe funkcje
                    gameWindow.draw(*maps.currentMap->getEnemies()[i]);
                    checkBulletEnemyCollision();
                    maps.currentMap->handleEnemies();
                }


            }

        }
        //jeżeli mapa posiada klucz do otwarcia jakiś drzwi to też jest to obsługiwane
        if (maps.currentMap->hasKey()) {
            gameWindow.draw(maps.currentMap->getKey());
        }
        //rysowanie portalu do następnego poziomu
        gameWindow.draw(maps.currentMap->getNextLevel());
        //rysowanie platform mapy i sprawdzanie kolizji gracza i przeciwników z nimi
        for (int i = 0; i < maps.currentMap->getPlatforms().size(); i++) {
            gameWindow.draw(maps.currentMap->getPlatforms()[i]);
            player.checkCollision(maps.currentMap->getPlatforms()[i]);
            player.bulletCollion(maps.currentMap->getPlatforms()[i]);
            if (maps.currentMap->hasEnemies()) {
                for (auto enemy: maps.currentMap->getEnemies()) {
                    enemy->checkCollisiion(maps.currentMap->getPlatforms()[i]);
                }
            }


        }
    } else{
        //ekran game over
        gameWindow.clear(sf::Color::White);
    }
    gameWindow.display();

}







