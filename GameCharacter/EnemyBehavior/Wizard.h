//
// Created by leoco on 27/05/2020.
//

#ifndef ALIENATOR_WIZARD_H
#define ALIENATOR_WIZARD_H

#include "EnemyBehavior.h"

class Wizard: public EnemyBehavior {
public:
    bool patrol(sf::Sprite hero,sf::Sprite enemy ,float deltaT, float directionX) override;
    void fight() override ;
};

#endif //ALIENATOR_WIZARD_H
