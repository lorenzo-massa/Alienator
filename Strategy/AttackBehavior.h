//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_ATTACKBEHAVIOR_H
#define ALIENATOR_ATTACKBEHAVIOR_H

#include <SFML/Audio.hpp>

#define BLOCK_SIZE 64

class AttackBehavior{
public:
    virtual void attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move,float& enemyDir)=0;

    AttackBehavior();

    virtual ~AttackBehavior();

};
#endif //ALIENATOR_ATTACKBEHAVIOR_H
