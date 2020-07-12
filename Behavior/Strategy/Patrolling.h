//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_PATROLLING_H
#define ALIENATOR_PATROLLING_H

#include <SFML/System/Vector2.hpp>

class Patrolling{
public:
    virtual bool patrol(float deltaT, sf::Vector2f enemyPos,sf::Vector2f heroPos,sf::Vector2f patrolDistance, float direction) ;
};
#endif //ALIENATOR_PATROLLING_H
