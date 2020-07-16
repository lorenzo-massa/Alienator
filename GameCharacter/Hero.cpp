//
// Created by Leonardo Corsini on 27/05/2020.
//

#include <AssetsManager.h>
#include "Hero.h"

Hero::Hero(int type, int hp, int ar, int am, sf::Vector2f s, sf::Vector2f pos, sf::Vector2f dir, float speedCoeff, int coins)
        : GameCharacter(hp, ar, am, s, pos, dir, speedCoeff), type(type), coins(coins) {
    setTexture(AssetManager::getAssetManager()->getTextures().at("Idle_1"));
    strTexture = "Idle_1";
    setPosition(pos);
    //setTextureRect(sf::IntRect(0,0,213.0f,428.0f));
    setScale(sf::Vector2f(0.25f, 0.25f));
    weapon = std::make_shared<Weapon>(120, 3.0f);
    clockPowerUp = sf::Clock();
    powerUpState = false;
    weaponHit=false;
}

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

sf::Vector2f Hero::move( float deltaT) {
    return GameCharacter::move( deltaT);
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

void Hero::addHealthPoint(int healthPoint) {
    this->healthPoint+=healthPoint;
    if(this->healthPoint>1000)
        this->healthPoint=1000;
}


int Hero::getType() const {
    return type;
}

void Hero::setType(int type) {
    Hero::type = type;
}

bool Hero::isWeaponHit() const {
    return weaponHit;
}

void Hero::setWeaponHit(bool weaponHit) {
    Hero::weaponHit = weaponHit;
}

Hero::~Hero() = default;





