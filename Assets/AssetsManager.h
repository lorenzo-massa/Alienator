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

    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, std::vector<sf::IntRect>> frames;
    static std::shared_ptr<sf::Font> font;

    static void setBackground(const std::shared_ptr<sf::RenderWindow>& targetWindow, float xT);

    static void initBackground(const std::shared_ptr<sf::RenderWindow>& targetWindow, float x);

    static float getXBackground();


private:
    static float xBackground;
};

#endif //ALIENATOR_ASSETSMANAGER_H
