//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_MINIGUN_H
#define ALIENATOR_MINIGUN_H

#include "Weapon.h"

class Minigun : virtual public Weapon{
public:
    explicit Minigun(int direction,int d=15,float fR=2);

    void fire() override ;

};

#endif //ALIENATOR_MINIGUN_H
