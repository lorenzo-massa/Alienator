//
// Created by leoco on 27/05/2020.
//

#include "Weapon.h"

Weapon::Weapon(int direction, int d, float fR) {

}

void Weapon::fire() {

}

void Weapon::setDamage(int d) {
    Weapon::damage = d;
}
int Weapon::getDamage() const {
    return Weapon::damage;
}

void Weapon::setFireRate(float fR) {
    Weapon::fireRate = fR;
}
float Weapon::getFireRate() {
    return Weapon::fireRate;
}

int Weapon::getPosX() const {
    return Weapon::posX;
}
void Weapon::setPosX(int posX) {
    Weapon::posX = posX;
}

int Weapon::getPosY() const {
    return Weapon::posY;
}
void Weapon::setPosY(int posY) {
    Weapon::posY = posY;
}

int Weapon::getDirection() const {
    return Weapon::direction;
}
void Weapon::setDirection(int direction) {
    Weapon::direction = direction;
}

