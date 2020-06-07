//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "AssetsManager.h"

std::map<std::string, sf::Texture> AssetManager::textures = std::map<std::string, sf::Texture>();
std::map<std::string, std::vector<sf::IntRect>> AssetManager::frames = std::map<std::string, std::vector<sf::IntRect>>();
std::map<std::string, sf::SoundBuffer> AssetManager::sounds = std::map<std::string, sf::SoundBuffer>();

std::unique_ptr<sf::Font> AssetManager::font = nullptr;


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

void AssetManager::setFrames() {
    /*
    //HERO
    std::vector<sf::IntRect> frame;
    for(int i = 0; i < 10; i++)
        frame.emplace_back(sf::IntRect(0 + i * 80, 0, 80, 65));
    frames.insert(std::make_pair("HERO_FRAMES", frame));
    frame.clear();
    //ARCHER
    for(int i = 0; i < 16; i++)
        frame.emplace_back(sf::IntRect(0 + i * 80, 0, 80, 83));
    frames.insert(std::make_pair("ARCHER_FRAMES", frame));
    frame.clear();
    //BRAWLER
    for(int i = 0; i < 20; i++)
        frame.emplace_back(sf::IntRect(0 + i * 579, 0, 579, 763));
    frames.insert(std::make_pair("BRAWLER_FRAMES", frame));
    frame.clear();
    //WATCHER
    for(int i = 0; i < 20; i++)
        frame.emplace_back(sf::IntRect(0 + i * 680, 0, 680, 472));
    frames.insert(std::make_pair("WATCHER_FRAMES", frame));
    frame.clear();
    //BOSS
    for(int i = 0; i < 14; i++)
        frame.emplace_back(sf::IntRect(0 +  i  * 835, 0,  835, 554));
    frames.insert(std::make_pair("BOSS_FRAMES", frame));
    frame.clear();
     */
}

void AssetManager::setBackground(std::shared_ptr<sf::RenderWindow> targetWindow) {
    sf::Sprite background(textures.at("BACKGROUND"));
    targetWindow->draw(background);
}
