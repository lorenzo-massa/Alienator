//
// Created by leoco on 10/07/2020.
//

#include "DistanceAttack.h"

void DistanceAttack::attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move,float &enemyDir) {

    enemyDir = heroPos.x < enemyPos.x ? 1.0f : -1.0f;

    if(std::abs(heroPos.x-enemyPos.x)>64.0f*6.0f){
        //move.x=0;
        enemyDir*=-1.0f;
    }
}
