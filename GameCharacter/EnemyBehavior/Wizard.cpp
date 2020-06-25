//
// Created by leoco on 27/05/2020.
//

#include "Wizard.h"



void Wizard::fight() {

}

bool Wizard::patrol(sf::Sprite hero, sf::Sprite enemy, float deltaT, float directionX) {
    return EnemyBehavior::patrol(hero, enemy, deltaT, directionX);
}

