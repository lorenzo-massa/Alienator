//
// Created by Leonardo Corsini on 27/05/2020.
//

#include "Weapon.h"

Weapon::Weapon(int d, float fR) : damage(d), fireRate(fR) {}

std::shared_ptr<Bullet> Weapon::fire(int x, int y, int damage, sf::Vector2f mousePosition) const {
    std::shared_ptr<Bullet> b = std::make_shared<Bullet>(damage, x, y, mousePosition);
    return b;
}

Weapon::Weapon() {

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

float Weapon::getFireRate() const {
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



