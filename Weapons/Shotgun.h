//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_SHOTGUN_H
#define ALIENATOR_SHOTGUN_H

#include "Weapon.h"

class Shotgun : virtual public Weapon{
public:
    explicit Shotgun(int direction,int d=25,float fR=0.75);

    void fire() override ;

};

#endif //ALIENATOR_SHOTGUN_H
