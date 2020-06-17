//
// Created by leoco on 27/05/2020.
//

#ifndef ALIENATOR_SENTINEL_H
#define ALIENATOR_SENTINEL_H

#include "EnemyBehavior.h"

class Sentinel: public EnemyBehavior {
public:
    void patrol() override;
    void fight() override ;
};
#endif //ALIENATOR_SENTINEL_H
