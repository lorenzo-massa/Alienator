//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_SNIPER_H
#define ALIENATOR_SNIPER_H

#include "Weapon.h"

class Sniper : virtual public Weapon{
public:
    explicit Sniper(int direction,int d=30,float fR=0.5);

    void fire() override ;
};

#endif //ALIENATOR_SNIPER_H
