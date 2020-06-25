//
// Created by leoco on 27/05/2020.
//

#include "Guard.h"



void Guard::fight() {

}

bool Guard::patrol(sf::Sprite hero, sf::Sprite enemy, float deltaT, float directionX) {
    return EnemyBehavior::patrol(hero, enemy, deltaT, directionX);
}
