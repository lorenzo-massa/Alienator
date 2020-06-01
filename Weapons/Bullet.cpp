//
// Created by leoco on 27/05/2020.
//

#include "Bullet.h"
#include "Weapon.h"

Bullet::Bullet(int dam, int d, int x, int y):damage(dam),direction(d),posX(x),posY(y){}

int Bullet::getDirection(int d) {
    return 0;
}
void Bullet::setDirection() {

}

int Bullet::getPosY() const {
    return 0;
}
void Bullet::setPosY(int y) {

}

int Bullet::getPosX() const {
    return 0;
}
void Bullet::setPosX(int x) {

}

void Bullet::move(int x, int y) {

}

int Bullet::getDamage() const {
    return damage;
}

void Bullet::setDamage(int damage) {
    Bullet::damage = damage;
}
