//
// Created by Maciej Alfut on 05/01/2024.
//

#include "TextureLoader.hpp"
#include "fmt/core.h"


//Mapowanie tekstur do łatwiejszej implementacji w klasach


TextureLoader::TextureLoader() {
    sf::Texture loader;
    sf::Font fLoader;
    if (!loader.loadFromFile("../Sprites/floor.png")){
        fmt::println("floor.png nie załadował sie");
    }else textureMap["floor"] = loader;
    if (!loader.loadFromFile("../Sprites/celing.png")){
        fmt::println("celing.png nie załadował sie");
    } else textureMap["celing"] = loader;
    if (!loader.loadFromFile("../Sprites/leftWall.png")){
        fmt::println("leftWall.png nie załadował sie");
    } else textureMap["leftWall"] = loader;
    if (!loader.loadFromFile("../Sprites/rightWall.png")){
        fmt::println("rightWall.png nie załadował sie");
    } else textureMap["rightWall"] = loader;
    if (!loader.loadFromFile("../Sprites/background.png")){
        fmt::println("background.png nie załadował sie");
    } else textureMap["background"] = loader;
    if (!loader.loadFromFile("../Sprites/platform.png")){
        fmt::println("platform.png nie załadował sie");
    } else textureMap["platform"] = loader;
    if (!loader.loadFromFile("../Sprites/door.png")){
        fmt::println("door.png nie załadował sie");
    } else textureMap["door"] = loader;
    if (!loader.loadFromFile("../Sprites/playerRight.png")){
        fmt::println("playerRight.png nie załadował sie");
    } else textureMap["playerRight"] = loader;
    if (!loader.loadFromFile("../Sprites/playerLeft.png")){
        fmt::println("playerLeft.png nie załadował sie");
    } else textureMap["playerLeft"] = loader;
    if (!loader.loadFromFile("../Sprites/enemyLeft.png")){
        fmt::println("enemyLeft.png nie załadował sie");
    } else textureMap["enemyLeft"] = loader;
    if (!loader.loadFromFile("../Sprites/enemyRight.png")){
        fmt::println("enemyRight.png nie załadował sie");
    } else textureMap["enemyRight"] = loader;
    if (!loader.loadFromFile("../Sprites/key.png")){
        fmt::println("key.png nie załadował sie");
    } else textureMap["key"] = loader;
    if (!loader.loadFromFile("../Sprites/portal.png")){
        fmt::println("key.png nie załadował sie");
    } else textureMap["portal"] = loader;
    if (!loader.loadFromFile("../Sprites/ghost.png")){
        fmt::println("ghost.png nie załadował sie");
    } else textureMap["ghost"] = loader;
    if (!loader.loadFromFile("../Sprites/ghost.png")){
        fmt::println("ghost.png nie załadował sie");
    } else textureMap["ghost"] = loader;
    if (!fLoader.loadFromFile("../Sprites/font.ttf")){
        fmt::println("font.ttf nie załadował sie");
    } else fontMap["font"] = fLoader;
    if (!fLoader.loadFromFile("../Sprites/hpup.png")){
        fmt::println("hpup.png nie załadował sie");
    } else textureMap["hpup"] = loader;
    if (!fLoader.loadFromFile("../Sprites/jumpheight.png")){
        fmt::println("jump.png nie załadował sie");
    } else textureMap["jump"] = loader;
    if (!fLoader.loadFromFile("../Sprites/biggerMagazine.png")){
        fmt::println("biggerMagazine.ttf nie załadował sie");
    } else textureMap["ammo"] = loader;






//    loader.loadFromFile("../Sprites/floor.png");

}
