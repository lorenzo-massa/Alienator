//
// Created by leoco on 27/05/2020.
//

#include "Bullet.h"


Bullet::Bullet(int dam, int d, int x, int y):damage(dam),direction(d),posX(x),posY(y){}

void Bullet::move(int x, int y/*,float dir,int v*/) {
   /* x+=v*10;
    y=dir*x;*/
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
