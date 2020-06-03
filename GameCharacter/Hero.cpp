//
// Created by leoco on 27/05/2020.
//

#include "Hero.h"

Hero::Hero(int hp, int ar, int am, int s) : GameCharacter(hp, ar, am, s) {

}

Hero::~Hero() {

}

int Hero::getCoins() const {
    return coins;
}
void Hero::setCoins(int coins) {
    Hero::coins = coins;
}

void Hero::shot(Weapon *weapon) {
    GameCharacter::shot(weapon);
}

void Hero::move(int posX, int posY, int speed, int direction) {
    GameCharacter::move(posX, posY, speed, direction);
}

void Hero::jump(int y) {
    GameCharacter::jump(y);
}

int Hero::receiveDamage(int points) {
    return GameCharacter::receiveDamage(points);
}

bool Hero::isLegalMovement(char comparison) {
    return GameCharacter::isLegalMovement(comparison);
}

