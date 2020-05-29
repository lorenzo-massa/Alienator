//
// Created by leoco on 27/05/2020.
//

#ifndef ALIENATOR_WIZARD_H
#define ALIENATOR_WIZARD_H

#include "EnemyBehavior.h"

class Wizard: public EnemyBehavior {
public:
    void patrol() override;
    void fight() override ;
};

#endif //ALIENATOR_WIZARD_H
