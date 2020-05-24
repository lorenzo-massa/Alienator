//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_BULLET_H
#define ALIENATOR_BULLET_H

#include "Weapon.h"

class Bullet{
public:
    Bullet();//TODO direction? posX,posY di weapon?
    ~Bullet(){}

    void move(int x,int y);

    void setPosX(int x);
    int getPosX() const;

    void setPosY(int y);
    int getPosY() const;

    void setDirection();
    int getDirection(int d);

private:
    int posX;
    int posY;
    int direction;
    Weapon* weapon;
};

#endif //ALIENATOR_BULLET_H
