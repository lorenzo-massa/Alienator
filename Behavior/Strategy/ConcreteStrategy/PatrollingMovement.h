//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_PATROLLINGMOVEMENT_H
#define ALIENATOR_PATROLLINGMOVEMENT_H

#include "../Movement.h"

class PatrollingMovement:virtual public Movement{
public:
    void movement()override ;
};
#endif //ALIENATOR_PATROLLINGMOVEMENT_H
