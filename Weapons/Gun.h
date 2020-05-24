//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_GUN_H
#define ALIENATOR_GUN_H

#include "Weapon.h"

class Gun : virtual public Weapon{
public:
    explicit Gun(int direction,int d=10,float fR=1.0);

    virtual void fire() override ;

};

#endif //ALIENATOR_GUN_H
