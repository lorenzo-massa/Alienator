//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_ASSETSMANAGER_H
#define ALIENATOR_ASSETSMANAGER_H


#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class AssetManager {
public:
    static void load();
    static void setFrames();

    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, std::vector<sf::IntRect>> frames;
    static std::map<std::string, sf::SoundBuffer> sounds;
    static std::unique_ptr<sf::Font> font;

    virtual ~AssetManager() = 0;


};

#endif //ALIENATOR_ASSETSMANAGER_H
