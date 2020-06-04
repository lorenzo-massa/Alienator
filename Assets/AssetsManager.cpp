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
        texture.loadFromFile("./Assets/Images/isAnimatedFull.png");
        textures.insert(std::make_pair("HERO", texture));
        texture.loadFromFile("./Assets/Images/archer.png");
        textures.insert(std::make_pair("ARCHER", texture));
        texture.loadFromFile("./Assets/Images/Background.png");
        textures.insert(std::make_pair("BACKGROUND", texture));
        texture.loadFromFile("./Assets/Images/coconut.png");
        textures.insert(std::make_pair("BULLET", texture));
        texture.loadFromFile("./Assets/Images/dinoWalk.png");
        textures.insert(std::make_pair("WATCHER", texture));
        texture.loadFromFile("./Assets/Images/heart.png");
        textures.insert(std::make_pair("HEART", texture));
        texture.loadFromFile("./Assets/Images/Lantern.png");
        textures.insert(std::make_pair("BRAWLER", texture));
        texture.loadFromFile("./Assets/Images/lolly.png");
        textures.insert(std::make_pair("CANDY", texture));
        texture.loadFromFile("./Assets/Images/platform.png");
        textures.insert(std::make_pair("PLATFORM", texture));
        texture.loadFromFile("./Assets/Images/BOSS.png");
        textures.insert(std::make_pair("BOSS", texture));

        font = std::make_unique<sf::Font>();
        font->loadFromFile("./Assets/Font/mainFont.otf");



        sound.loadFromFile("./Assets/Audio/heroJump.wav");
        sounds.insert(std::make_pair("HERO_JUMP", sound));
        sound.loadFromFile("./Assets/Audio/heroDamage.wav");
        sounds.insert(std::make_pair("HERO_DAMAGE", sound));
        sound.loadFromFile("./Assets/Audio/heroShoot.wav");
        sounds.insert(std::make_pair("HERO_SHOOT", sound));
        sound.loadFromFile("./Assets/Audio/enemyShoot.wav");
        sounds.insert(std::make_pair("ENEMY_SHOOT", sound));
        sound.loadFromFile("./Assets/Audio/archerDamage.wav");
        sounds.insert(std::make_pair("ARCHER_DAMAGE", sound));
        sound.loadFromFile("./Assets/Audio/watcherDamage.wav");
        sounds.insert(std::make_pair("WATCHER_DAMAGE", sound));
        sound.loadFromFile("./Assets/Audio/brawlerDamage.wav");
        sounds.insert(std::make_pair("BRAWLER_DAMAGE", sound));
        sound.loadFromFile("./Assets/Audio/bossDamage.wav");
        sounds.insert(std::make_pair("BOSS_DAMAGE", sound));
        sound.loadFromFile("./Assets/Audio/powerUp.wav");
        sounds.insert(std::make_pair("POWER_UP", sound));
        sound.loadFromFile("./Assets/Audio/reload.wav");
        sounds.insert(std::make_pair("RELOAD", sound));

    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }

}

void AssetManager::setFrames() {
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
}
