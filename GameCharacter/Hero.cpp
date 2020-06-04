//
// Created by leoco on 27/05/2020.
//

#include "Hero.h"

Hero::Hero(int hp, int ar, int am, sf::Vector2f s) : GameCharacter(hp, ar, am, s) {}
Hero::Hero(sf::Vector2f pos) :GameCharacter(pos){}
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

void Hero::move(sf:: Vector2f direction) {
    GameCharacter::move(direction);
}

float Hero::jump() {
    return GameCharacter::jump();
}

int Hero::receiveDamage(int points) {
    return GameCharacter::receiveDamage(points);
}

/*bool Hero::isLegalMovement(char comparison) {
    return GameCharacter::isLegalMovement(comparison);
}*/

