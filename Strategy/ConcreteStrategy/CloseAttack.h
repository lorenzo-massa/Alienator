//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_CLOSEATTACK_H
#define ALIENATOR_CLOSEATTACK_H


#include "../AttackBehavior.h"

class CloseAttack: virtual public AttackBehavior{
public:
    void attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move,float& enemyDir)override ;

    CloseAttack();

    ~CloseAttack()override ;
};
#endif //ALIENATOR_CLOSEATTACK_H
