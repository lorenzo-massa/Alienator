//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_GROUNDPATROLLING_H
#define ALIENATOR_GROUNDPATROLLING_H

#include "../Patrolling.h"


class GroundPatrolling: virtual public Patrolling{
public:
    bool patrol(float deltaT, sf::Vector2f enemyPos,sf::Vector2f heroPos,sf::Vector2f patrolDistance, float direction) override;
};
#endif //ALIENATOR_GROUNDPATROLLING_H