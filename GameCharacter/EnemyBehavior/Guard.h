//
// Created by leoco on 27/05/2020.
//

#ifndef ALIENATOR_GUARD_H
#define ALIENATOR_GUARD_H

#include "EnemyBehavior.h"

class Guard: public EnemyBehavior {
public:
    bool patrol(sf::Sprite hero,sf::Sprite enemy ,float deltaT, float directionX) override;
    void fight() override ;
};
#endif //ALIENATOR_GUARD_H
