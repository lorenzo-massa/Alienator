//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_WEAPON_H
#define ALIENATOR_WEAPON_H

#include "Bullet.h"
#include <memory>

class Weapon {
public:
    Weapon();

    explicit Weapon(int d = 10, float fR = 1.0);

    virtual ~Weapon();

    std::shared_ptr<Bullet> fire(int x, int y, int damage, sf::Vector2f mousePosition) const;

    void setDamage(int d);

    int getDamage() const;

    void setFireRate(float fR);

    float getFireRate() const;

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    int getDirection() const;

    void setDirection(int direction);

    int getCurrentAmmo() const;

    void setCurrentAmmo(int currentAmmo);

protected:
    int damage;
    float fireRate;
    int currentAmmo;
    int posX;
    int posY;
    int direction;
};

#endif //ALIENATOR_WEAPON_H
