//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_ASSAULT_H
#define ALIENATOR_ASSAULT_H

#include "Weapon.h"

class Assault : virtual public Weapon{
public:
    explicit Assault(int direction,int d=15,float fR=1.5);

    void fire() override ;
};

#endif //ALIENATOR_ASSAULT_H
