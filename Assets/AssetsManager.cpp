//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "AssetsManager.h"

std::map<std::string, sf::Texture> AssetManager::textures = std::map<std::string, sf::Texture>();
std::map<std::string, std::vector<sf::IntRect>> AssetManager::frames = std::map<std::string, std::vector<sf::IntRect>>();
//std::map<std::string, sf::SoundBuffer> AssetManager::sounds = std::map<std::string, sf::SoundBuffer>();

std::shared_ptr<sf::Font> AssetManager::font = nullptr;

float AssetManager::xBackground = 0;

void AssetManager::load() {


    try {

        sf::Texture texture;
        sf::SoundBuffer sound;


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

        texture.loadFromFile("Assets/Images//Object/mystery.png");
        textures.insert(std::make_pair("MYSTERY", texture));

        texture.loadFromFile("Assets/Images//Object/bullet.png");
        textures.insert(std::make_pair("Bullet", texture));

        texture.loadFromFile("Assets/Images//Object/portal.png");
        textures.insert(std::make_pair("PORTAL", texture));

        const int nTiles = 16;
        for (int i = 1; i < nTiles + 1; ++i) {
            texture.loadFromFile("Assets/Images/Tiles/" + std::to_string(i) + ".png");
            textures.insert(std::make_pair(std::to_string(i), texture));
        }

        texture.loadFromFile("Assets/Images/Alien/alien_green/Idle_1.png");
        textures.insert(std::make_pair("Idle_1", texture));

        texture.loadFromFile("Assets/Images/Alien/alien_green/Idle_1_Reversed.png");
        textures.insert(std::make_pair("Idle_1_Reversed", texture));

        for (int i = 1; i < 7; ++i) {
            texture.loadFromFile("Assets/Images/Alien/alien_green/Run_" + std::to_string(i) + ".png");
            textures.insert(std::make_pair("Run_" + std::to_string(i), texture));

            texture.loadFromFile("Assets/Images/Alien/alien_green/Run_" + std::to_string(i) + "_Reversed.png");
            textures.insert(std::make_pair("Run_" + std::to_string(i) + "_Reversed", texture));
        }

        texture.loadFromFile("Assets/Images/Alien/alien_blue/Idle_1.png");
        textures.insert(std::make_pair("Blue_Idle_1", texture));

        texture.loadFromFile("Assets/Images/Alien/alien_blue/Idle_1_Reversed.png");
        textures.insert(std::make_pair("Blue_Idle_1_Reversed", texture));

        for (int i = 1; i < 7; ++i) {
            texture.loadFromFile("Assets/Images/Alien/alien_blue/Run_" + std::to_string(i) + ".png");
            textures.insert(std::make_pair("Blue_Run_" + std::to_string(i), texture));

            texture.loadFromFile("Assets/Images/Alien/alien_blue/Run_" + std::to_string(i) + "_Reversed.png");
            textures.insert(std::make_pair("Blue_Run_" + std::to_string(i) + "_Reversed", texture));
        }

        texture.loadFromFile("Assets/Images/Alien/alien_gray/Idle_1.png");
        textures.insert(std::make_pair("Gray_Idle_1", texture));

        texture.loadFromFile("Assets/Images/Alien/alien_gray/Idle_1_Reversed.png");
        textures.insert(std::make_pair("Gray_Idle_1_Reversed", texture));

        for (int i = 1; i < 7; ++i) {
            texture.loadFromFile("Assets/Images/Alien/alien_gray/Run_" + std::to_string(i) + ".png");
            textures.insert(std::make_pair("Gray_Run_" + std::to_string(i), texture));

            texture.loadFromFile("Assets/Images/Alien/alien_gray/Run_" + std::to_string(i) + "_Reversed.png");
            textures.insert(std::make_pair("Gray_Run_" + std::to_string(i) + "_Reversed", texture));
        }


        texture.loadFromFile("Assets/Images/Alien/alien_red/Idle_1.png");
        textures.insert(std::make_pair("Red_Idle_1", texture));

        texture.loadFromFile("Assets/Images/Alien/alien_red/Idle_1_Reversed.png");
        textures.insert(std::make_pair("Red_Idle_1_Reversed", texture));

        for (int i = 1; i < 7; ++i) {
            texture.loadFromFile("Assets/Images/Alien/alien_red/Run_" + std::to_string(i) + ".png");
            textures.insert(std::make_pair("Red_Run_" + std::to_string(i), texture));

            texture.loadFromFile("Assets/Images/Alien/alien_red/Run_" + std::to_string(i) + "_Reversed.png");
            textures.insert(std::make_pair("Red_Run_" + std::to_string(i) + "_Reversed", texture));
        }


        font = std::make_shared<sf::Font>();
        font->loadFromFile("Assets/Font/youre gone.ttf");



        /*
        sound.loadFromFile("./Assets/Audio/heroJump.wav");
        sounds.insert(std::make_pair("HERO_JUMP", sound));
        */

    } catch (const std::exception &exception) {
        std::cerr << exception.what() << std::endl;
    }

}

void AssetManager::setBackground(std::shared_ptr<sf::RenderWindow> targetWindow, float xT) {
    sf::Sprite background(textures.at("BACKGROUND"));
    xBackground += xT;
    background.setPosition(xBackground, 0);
    targetWindow->draw(background);
}

void AssetManager::initBackground(std::shared_ptr<sf::RenderWindow> targetWindow, float x) {
    sf::Sprite background(textures.at("BACKGROUND"));
    xBackground = x;
    background.setPosition(xBackground, 0);
    targetWindow->draw(background);
}

float AssetManager::getXBackground() {
    return xBackground;
}
