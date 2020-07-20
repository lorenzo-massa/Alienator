//
// Created by leoco on 10/07/2020.
//

#include <cmath>
#include "DistanceAttack.h"

void DistanceAttack::attack(sf::Vector2f heroPos,sf::Vector2f enemyPos, sf::Vector2f &move,float &enemyDir) {

    float eps=15.0f;
    if(std::abs(heroPos.x-enemyPos.x)<6.0f*BLOCK_SIZE){
        enemyDir = heroPos.x < enemyPos.x ? 1.0f : -1.0f;
    }

    else if(std::abs(heroPos.x-enemyPos.x)>6.0f*BLOCK_SIZE){
        enemyDir = heroPos.x < enemyPos.x ? -1.0f : 1.0f;
    }

    if(std::abs(heroPos.x-enemyPos.x)>6.0f*BLOCK_SIZE-eps && std::abs(heroPos.x-enemyPos.x)<6.0f*BLOCK_SIZE+eps){
        enemyDir=0;
        move.x=0;
    }
}

DistanceAttack::~DistanceAttack() = default;

DistanceAttack::DistanceAttack() : Attack(){}

