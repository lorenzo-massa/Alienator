//
// Created by leoco on 27/05/2020.
//

#include <SFML/Graphics/Sprite.hpp>
#include "Bullet.h"


Bullet::Bullet(int dam, int d, int x, int y):damage(dam),direction(d),posX(x),posY(y){}

void Bullet::move(float dir,float coeffAng,float dT) {
    float moveX=5.0f*64.0f*dT;
    float moveY;
    moveY=coeffAng*moveX*dT;

    //sf::Sprite move(moveX,moveY);
}//TODO retta su cui si muove bullet

int Bullet::getDirection()const {
    return direction;
}
void Bullet::setDirection(int d) {
    direction=d;
}

int Bullet::getPosY() const {
    return posY;
}
void Bullet::setPosY(int y) {
    posY=y;
}

int Bullet::getPosX() const {
    return posX;
}
void Bullet::setPosX(int x) {
    posX=x;
}

int Bullet::getDamage() const {
    return damage;
}
void Bullet::setDamage(int damage) {
    Bullet::damage = damage;
}
