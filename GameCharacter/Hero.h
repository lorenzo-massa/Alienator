//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_HERO_H
#define ALIENATOR_HERO_H

#include "GameCharacter.h"

class Hero :virtual public GameCharacter{
public:
    Hero();
    ~Hero();

private:
    int coins;

};

#endif //ALIENATOR_HERO_H
