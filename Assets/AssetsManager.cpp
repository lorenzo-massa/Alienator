//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "AssetsManager.h"

std::map<std::string, sf::Texture> AssetManager::textures = std::map<std::string, sf::Texture>();
std::map<std::string, std::vector<sf::IntRect>> AssetManager::frames = std::map<std::string, std::vector<sf::IntRect>>();
std::map<std::string, sf::SoundBuffer> AssetManager::sounds = std::map<std::string, sf::SoundBuffer>();

std::unique_ptr<sf::Font> AssetManager::font = nullptr;

float AssetManager::xBackground = 0;

void AssetManager::load() {


    try {


        sf::Texture texture;
        sf::SoundBuffer sound;

        texture.loadFromFile("Assets/Images/Object/Hero.png");
        textures.insert(std::make_pair("HERO", texture));

        texture.loadFromFile("Assets/Images/BG/bg.jpg");
        textures.insert(std::make_pair("BACKGROUND", texture));

        texture.loadFromFile("Assets/Images//Object/coin.png");
        textures.insert(std::make_pair("COINS", texture));

        texture.loadFromFile("Assets/Images//Object/munitions.png");
        textures.insert(std::make_pair("MUNITIONS", texture));

        texture.loadFromFile("Assets/Images//Object/firerate.png");
        textures.insert(std::make_pair("FIRE_RATE", texture));

        texture.loadFromFile("Assets/Images//Object/speed.png");
        textures.insert(std::make_pair("SPEED", texture));

        texture.loadFromFile("Assets/Images//Object/damageboost.png");
        textures.insert(std::make_pair("DAMAGE_BOOST", texture));

        texture.loadFromFile("Assets/Images//Object/invincibility.png");
        textures.insert(std::make_pair("INVICIBILITY", texture));


        const int nTiles = 16;
        for (int i = 1; i < nTiles+1; ++i) {
            texture.loadFromFile("Assets/Images/Tiles/"+std::to_string(i)+".png");
            textures.insert(std::make_pair(std::to_string(i), texture));
        }

        for (int i = 1; i < 4; ++i) {
            texture.loadFromFile("Assets/Images/Alien/alien_green/Idle_"+std::to_string(i)+".png");
            textures.insert(std::make_pair("Idle_"+std::to_string(i), texture));
        }
        for (int i = 1; i < 7; ++i) {
            texture.loadFromFile("Assets/Images/Alien/alien_green/Walk_"+std::to_string(i)+".png");
            textures.insert(std::make_pair("Walk_"+std::to_string(i), texture));
        }


        font = std::make_unique<sf::Font>();
        font->loadFromFile("Assets/Font/youre gone.ttf");



        /*
        sound.loadFromFile("./Assets/Audio/heroJump.wav");
        sounds.insert(std::make_pair("HERO_JUMP", sound));
        */

    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }

}

void AssetManager::setBackground(std::shared_ptr<sf::RenderWindow> targetWindow, float xT) {
    sf::Sprite background(textures.at("BACKGROUND"));
    xBackground += xT;
    background.setPosition(xBackground, 0);
    targetWindow->draw(background);
}

float AssetManager::getXBackground() {
    return xBackground;
}
