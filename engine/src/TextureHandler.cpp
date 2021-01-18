#include "../include/TextureHandler.hpp"

#include <fstream>

#include <iostream>

namespace engine {
    TextureHandler::TextureHandler() {

    }

    void TextureHandler::LoadTextures() {

        texturemap.begin();
        std::ifstream file("textureslist.txt");
        std::string line;
        int i = 0, numberofLines = 0;
        
        while (std::getline(file, line)) {
            numberofLines++;
        }
        file.clear();
        file.seekg(0);
        
        retText = new sf::Texture();
        text = new sf::Texture * [numberofLines];

        for (i = 0; i < numberofLines; i++) {
            text[i] = new sf::Texture();
        }
        i = 0;
        while (std::getline(file, line)) {

            text[i]->loadFromFile(line);
            texturemap.insert(std::pair < std::string, sf::Texture* >(line, text[i]));
            i++;
        }
    }

    sf::Texture* TextureHandler::getTexture(std::string str) {

        retText = texturemap.at(str);
        return retText;
    }

}