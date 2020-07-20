//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "AssetsManager.h"

AssetManager* AssetManager::myAssetManager = nullptr;

AssetManager::AssetManager() {
    load();
}

AssetManager* AssetManager::getAssetManager(){
    if (myAssetManager == nullptr)
        myAssetManager = new AssetManager();
    return myAssetManager;
}

void AssetManager::load() {

    try {

        sf::Texture texture;

        texture.loadFromFile("Assets/Images/BG/bg.jpg");
        textures.insert(std::make_pair("BACKGROUND", texture));

        texture.loadFromFile("Assets/Images//Object/heart.png");
        textures.insert(std::make_pair("HEALTH", texture));

        texture.loadFromFile("Assets/Images//Object/coin.png");
        textures.insert(std::make_pair("COINS", texture));

        texture.loadFromFile("Assets/Images//Object/munitionsReload.png");
        textures.insert(std::make_pair("MUNITIONS", texture));

        texture.loadFromFile("Assets/Images//Object/mystery.png");
        textures.insert(std::make_pair("MYSTERY", texture));

        texture.loadFromFile("Assets/Images//Object/bullet.png");
        textures.insert(std::make_pair("Bullet", texture));

        texture.loadFromFile("Assets/Images//Object/portal.png");
        textures.insert(std::make_pair("PORTAL", texture));

        texture.loadFromFile("Assets/Images//Object/BulletGUI.png");
        textures.insert(std::make_pair("BulletGUI", texture));

        texture.loadFromFile("Assets/Images//Object/BulletGUIEmpty.png");
        textures.insert(std::make_pair("BulletGUIEmpty", texture));

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


    } catch (const std::exception &exception) {
        std::cerr << exception.what() << std::endl;
    }

}

void AssetManager::setBackground(const std::shared_ptr<sf::RenderWindow>& targetWindow, float xT) {
    sf::Sprite background(textures.at("BACKGROUND"));
    xBackground += xT;
    background.setPosition(xBackground, 0);
    targetWindow->draw(background);
}

void AssetManager::initBackground(const std::shared_ptr<sf::RenderWindow>& targetWindow, float x) {
    sf::Sprite background(textures.at("BACKGROUND"));
    xBackground = x;
    background.setPosition(xBackground, 0);
    targetWindow->draw(background);
}

const std::map<std::string, sf::Texture> &AssetManager::getTextures() const {
    return textures;
}

void AssetManager::setTextures(const std::map<std::string, sf::Texture> &textures) {
    AssetManager::textures = textures;
}

const std::map<std::string, std::vector<sf::IntRect>> &AssetManager::getFrames() const {
    return frames;
}

void AssetManager::setFrames(const std::map<std::string, std::vector<sf::IntRect>> &frames) {
    AssetManager::frames = frames;
}

const std::shared_ptr<sf::Font> &AssetManager::getFont() const {
    return font;
}

void AssetManager::setFont(const std::shared_ptr<sf::Font> &font) {
    AssetManager::font = font;
}

float AssetManager::getXBackground() const {
    return xBackground;
}

AssetManager::~AssetManager() = default;


