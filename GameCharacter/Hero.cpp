//
// Created by leoco on 27/05/2020.
//

#include <AssetsManager.h>
#include "Hero.h"

Hero::Hero(int type, int hp, int ar, int am, sf::Vector2f s,sf::Vector2f pos,float dir, int coins) : GameCharacter(hp, ar, am, s,pos,dir), type(type),coins(coins) {
    setTexture(AssetManager::textures.at("Idle_1"));
    strTexture = "Idle_1";
    setPosition(pos);
    //setTextureRect(sf::IntRect(0,0,213.0f,428.0f));
    setScale(sf::Vector2f(0.25f,0.25f));
}
Hero::~Hero() {}

int Hero::getCoins() const {
    return coins;
}
void Hero::setCoins(int coins) {
    Hero::coins = coins;
}

void Hero::shot(Weapon *weapon) {
    GameCharacter::shot(weapon);
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


Hero::Hero() {

}

/*bool Hero::isLegalMovement(char comparison) {
    return GameCharacter::isLegalMovement(comparison);
}*/

