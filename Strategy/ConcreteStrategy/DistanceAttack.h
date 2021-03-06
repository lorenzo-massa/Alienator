//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_DISTANCEATTACK_H
#define ALIENATOR_DISTANCEATTACK_H

#include "../AttackBehavior.h"

class DistanceAttack:virtual public AttackBehavior{
public:
    void attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move, float& enemyDir) override ;

    DistanceAttack();

    ~DistanceAttack() override ;
};
#endif //ALIENATOR_DISTANCEATTACK_H
