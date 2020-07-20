//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_ATTACK_H
#define ALIENATOR_ATTACK_H

#include <SFML/Audio.hpp>

#define BLOCK_SIZE 64

class Attack{
public:
    virtual void attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move,float& enemyDir)=0;

    Attack();

    virtual ~Attack();

};
#endif //ALIENATOR_ATTACK_H
