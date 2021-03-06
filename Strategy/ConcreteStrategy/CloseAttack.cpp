//
// Created by leoco on 10/07/2020.
//
#include "CloseAttack.h"



void CloseAttack::attack(sf::Vector2f heroPos, sf::Vector2f enemyPos,sf::Vector2f &move, float &enemyDir) {

    enemyDir = heroPos.x < enemyPos.x ? -1.0f : 1.0f;

    if(std::abs(heroPos.x-enemyPos.x)<3.0f*BLOCK_SIZE){
        move.x=0;
        enemyDir=0;
    }

}

CloseAttack::~CloseAttack() = default;

CloseAttack::CloseAttack(): AttackBehavior() {}
