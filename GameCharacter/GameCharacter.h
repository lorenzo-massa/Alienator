//
// Created by leoco on 23/05/2020.
//

#ifndef ALIENATOR_GAMECHARACTER_H
#define ALIENATOR_GAMECHARACTER_H

#include "../Weapons/Weapon.h"

class GameCharacter{
public:
    GameCharacter(int hp,int ar,int am,int s);

    ~GameCharacter();

    virtual int reciveDamage(int points);

    virtual void move(int x,int y);

    virtual void jump(int x,int y);

    virtual void shot(Weapon* weapon);

    int getPosX() const;
    void setPosX(int posX);

    int getPosY() const;
    void setPosY(int posY);

    int getHealthPoint() const;
    void setHealthPoint(int healthPoint);

    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

protected:
    int posX;
    int posY;
    int healthPoint;
    int armor;
    int speed;
    int ammo;
    Weapon * weapon;
};

#endif //ALIENATOR_GAMECHARACTER_H