//
// Created by leoco on 10/07/2020.
//

#include "Patrolling.h"

bool Patrolling::patrol( sf::Vector2f enemyPos, sf::Vector2f heroPos, sf::Vector2f patrolDistance,float &direction) {
    return false;
}
const std::shared_ptr<sf::Clock> &Patrolling::getPatrolClock() const {
    return patrolClock;
}

void Patrolling::setPatrolClock(const std::shared_ptr<sf::Clock> &patrolClock) {
    Patrolling::patrolClock = patrolClock;
}

Patrolling::Patrolling() {
    patrolClock=std::make_shared<sf::Clock>();
}
