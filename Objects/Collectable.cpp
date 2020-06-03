//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "Collectable.h"

Collectable::Collectable(){
    sprite = std::make_shared<sf::Sprite>();
    skin = std::make_shared<sf::Texture>();

    powerUp = PowerUp();
}

Collectable::Collectable(std::string type){
    sprite = std::make_shared<sf::Sprite>();
    skin = std::make_shared<sf::Texture>();

    powerUp = PowerUp(type);
}

Collectable::~Collectable(){
}

const std::shared_ptr<sf::Sprite> &Collectable::getSprite() const {
    return sprite;
}

void Collectable::setSprite(const std::shared_ptr<sf::Sprite> &sprite) {
    Collectable::sprite = sprite;
}

const std::shared_ptr<sf::Texture> &Collectable::getSkin() const {
    return skin;
}

void Collectable::setSkin(const std::shared_ptr<sf::Texture> &skin) {
    Collectable::skin = skin;
}

const PowerUp &Collectable::getPowerUp() const {
    return powerUp;
}

void Collectable::setPowerUp(const PowerUp &powerUp) {
    Collectable::powerUp = powerUp;
}
