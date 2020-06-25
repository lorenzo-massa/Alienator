//
// Created by leoco on 27/05/2020.
//

#include "Sentinel.h"
//#include "../Weapons/Sniper.h"



void Sentinel::fight() {

}

bool Sentinel::patrol(sf::Sprite hero, sf::Sprite enemy, float deltaT, float directionX) {
    return EnemyBehavior::patrol(hero, enemy, deltaT, directionX);
}
