//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_WEAPON_H
#define ALIENATOR_WEAPON_H

#include "Bullet.h"

class Weapon {
public:
    Weapon();
    explicit Weapon(int direction,int d=10,float fR=1.0);
    virtual ~Weapon(){}

    virtual void fire();

    void setDamage(int d);
    int getDamage()const;

    void setFireRate(float fR);
    float getFireRate();

    int getPosX() const;
    void setPosX(int posX);

    int getPosY() const;
    void setPosY(int posY);

    int getDirection() const;
    void setDirection(int direction);

protected:
    int damage;
    float fireRate;
    int posX;
    int posY;
    int direction;
};

#endif //ALIENATOR_WEAPON_H
