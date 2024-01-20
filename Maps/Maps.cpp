//
// Created by Maciej Alfut on 26/12/2023.
//

//ta klasa to trochę niewypał
//oryginalny pomysł był aby mapy losowały się
//kod został zmieniany dużo razy
//jedyne co tu zostało zaimplementowane to logika niektórych map
//gra przez to może nie zaczytywać map poprawnie
//jeżeli Panu nie działa przechodzenie po kolei do map - można ustawić to manualnie za co przepraszam

#include "Maps.hpp"
#include "MapThree/mapThree.hpp"

Maps::Maps() {
//
    currentMap = new mapOne;
}


//Metoda losująca mapape
void Maps::randomMap() {
//    index = (index + 1) % maps.size();
//
//    // Ustaw currentMap na mapę wskazywaną przez zaktualizowany indeks
//    currentMap = maps[index];
}

//aktualizowanie każdej mapy
void Maps::update(Player &player) {
    //logika dla mapy numer 1

    switch (currentMap->whichMap()) {
        case 1:
            if (player.getGlobalBounds().intersects(currentMap->getKey().getGlobalBounds())) {
                fmt::println("{}", "key");
                currentMap->openDoors();
                currentMap->handleKey();
            }
            if (player.getGlobalBounds().intersects(currentMap->getNextLevel().getGlobalBounds())) {
                fmt::println("{}", "Nextlevel");
                player.setPosition(800.f, 400.f);
                currentMap = new mapTwo;

            }
            break;
        case 2:
            if (currentMap->getEnemies().size() == 0) {
                currentMap->enableNextLevel();
            }
            if (player.getGlobalBounds().intersects(currentMap->getNextLevel().getGlobalBounds())) {
                player.setPosition(800.f, 400.f);

                currentMap = new mapThree;
                break;
                case 3:
                    if (currentMap->getEnemies().size() == 0) {
                        currentMap->enableNextLevel();
                    }
                if (player.getGlobalBounds().intersects(currentMap->getKey().getGlobalBounds())) {
                    currentMap->handleKey();
                }
                if (player.getGlobalBounds().intersects(currentMap->getNextLevel().getGlobalBounds())) {
                    randomMap();
                    player.setPosition(800.f, 300.f);
                }
                break;
            }
    }
}



