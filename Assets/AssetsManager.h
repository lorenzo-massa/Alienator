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

    AssetManager();

    virtual ~AssetManager();

    static std::shared_ptr<AssetManager> getAssetManager();

    const std::map<std::string, sf::Texture> &getTextures() const;

    void setTextures(const std::map<std::string, sf::Texture> &textures);

    const std::map<std::string, std::vector<sf::IntRect>> &getFrames() const;

    void setFrames(const std::map<std::string, std::vector<sf::IntRect>> &frames);

    const std::shared_ptr<sf::Font> &getFont() const;

    void setFont(const std::shared_ptr<sf::Font> &font);

    void setBackground(const std::shared_ptr<sf::RenderWindow>& targetWindow, float xT);

    void initBackground(const std::shared_ptr<sf::RenderWindow>& targetWindow, float x);

    float getXBackground() const;



private:

    void load();

    static std::shared_ptr<AssetManager> myAssetManager;

    std::map<std::string, sf::Texture> textures;
    std::map<std::string, std::vector<sf::IntRect>> frames;
    std::shared_ptr<sf::Font> font;

    float xBackground;
};

#endif //ALIENATOR_ASSETSMANAGER_H
