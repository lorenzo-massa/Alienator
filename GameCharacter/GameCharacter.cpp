//
// Created by leoco on 27/05/2020.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int ar, int am, int s) {

}

int GameCharacter::receiveDamage(int points) {
    return 0;
}

void GameCharacter::move(int x, int y) {

}

void GameCharacter::jump(int x, int y) {

}

void GameCharacter::shot(Weapon *weapon) {
    weapon->fire();
}

int GameCharacter::getPosX() const {
    return GameCharacter::posX;
}
void GameCharacter::setPosX(int posX) {
    GameCharacter::posX = posX;
}

int GameCharacter::getPosY() const {
    return GameCharacter::posY;
}

void GameCharacter::setPosY(int posY) {
    GameCharacter::posY = posY;
}

int GameCharacter::getHealthPoint() const {
    return GameCharacter::healthPoint;
}
void GameCharacter::setHealthPoint(int healthPoint) {
    GameCharacter::healthPoint=healthPoint;
}

Weapon *GameCharacter::getWeapon() {
    return weapon;
}
void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon=weapon;
}

int GameCharacter::getArmor() const {
    return armor;
}
void GameCharacter::setArmor(int armor) {
    GameCharacter::armor = armor;
}

int GameCharacter::getSpeed() const {
    return speed;
}
void GameCharacter::setSpeed(int speed) {
    GameCharacter::speed = speed;
}

int GameCharacter::getAmmo() const {
    return ammo;
}
void GameCharacter::setAmmo(int ammo) {
    GameCharacter::ammo = ammo;
}

GameCharacter::~GameCharacter() {

}

