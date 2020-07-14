//
// Created by leoco on 10/07/2020.
//

#include <cmath>
#include "DistanceAttack.h"

void DistanceAttack::attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move,float &enemyDir) {

    float eps=64.0f*10.0f;
    if(std::abs(heroPos.x-enemyPos.x)<64.0f*6.0f){
        enemyDir = heroPos.x < enemyPos.x ? 1.0f : -1.0f;
    }

    if(std::abs(heroPos.x-enemyPos.x)>64.0f*6.0f){
        //if(std::fabs(move.x)<eps)
            enemyDir = heroPos.x < enemyPos.x ? -1.0f : 1.0f;
    }

    if(std::abs(heroPos.x-enemyPos.x)<eps){
        enemyDir=0;
    }
}
