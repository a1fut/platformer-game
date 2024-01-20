//
// Created by Maciej Alfut on 20/01/2024.
//

#include "Items.hpp"

//tu miała być zaimplementowana klasa ale nie zdążyłem
//aktualizacja statystyk gracza miała polegać na podnoszenie przedmiotów i zapisywanie to do gracza statystyk
//chciałem zrobić to zwykłym intesectem, oraz setterem z klasy player
//itemsy miały się spawnować w itemsRoomie który zdążyłem zrobić tylko pobieżnie
Items::Items() {
    hpUp.setTexture(tl.textureMap["hpup"]);
    highJump.setTexture(tl.textureMap["jump"]);
    ammoUp.setTexture(tl.textureMap["ammo"]);
}
