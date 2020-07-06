//
// Created by Leonardo Corsini on 27/05/2020.
//

#include <AssetsManager.h>
#include "Hero.h"

Hero::Hero(int type, int hp, int ar, int am, sf::Vector2f s,sf::Vector2f pos,float dir, int coins) : GameCharacter(hp, ar, am, s,pos,dir), type(type),coins(coins) {
    setTexture(AssetManager::textures.at("Idle_1"));
    strTexture = "Idle_1";
    setPosition(pos);
    //setTextureRect(sf::IntRect(0,0,213.0f,428.0f));
    setScale(sf::Vector2f(0.25f,0.25f));

    clockPowerUp = sf::Clock();
}
Hero::Hero() {}
Hero::~Hero() {}

int Hero::getCoins() const {
    return coins;
}
void Hero::setCoins(int coins) {
    Hero::coins = coins;
}

std::shared_ptr<Bullet> Hero::shot(sf::Vector2f mousePosition) {
    ammo--;
    return GameCharacter::shot(mousePosition);
}

sf::Vector2f Hero::move(sf:: Vector2f direction, float deltaT) {
    return GameCharacter::move(direction,deltaT);
}

void Hero::jump() {
    GameCharacter::jump();
}

int Hero::receiveDamage(int points) {
    return GameCharacter::receiveDamage(points);
}

void Hero::addCoins(int coins) {
    this->coins += coins;
}

void Hero::addAmmo(int ammo) {
    this->ammo += ammo;
}

int Hero::getType() const {
    return type;
}

void Hero::setType(int type) {
    Hero::type = type;
}





