//
// Created by Maciej Alfut on 05/01/2024.
//

#ifndef SFMLTEST_TEXTURELOADER_HPP
#define SFMLTEST_TEXTURELOADER_HPP
#include "SFML/Graphics.hpp"

class TextureLoader {
    //Implementacja loadera tekstur w każdej klasie która będzie
    //miała jakąś teksturę
public:
    TextureLoader();
    std::map<std::string, sf::Texture> textureMap;
    std::map<std::string, sf::Font> fontMap;
};


#endif //SFMLTEST_TEXTURELOADER_HPP
