//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_FIGHTINGMOVEMENT_H
#define ALIENATOR_FIGHTINGMOVEMENT_H
#include "../Movement.h"

class FightingMovement:virtual public Movement{
public:
    void movement() override;
};
#endif //ALIENATOR_FIGHTINGMOVEMENT_H
