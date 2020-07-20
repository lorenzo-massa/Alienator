//
// Created by leoco on 10/07/2020.
//

#include "Patrolling.h"

const std::shared_ptr<sf::Clock> &Patrolling::getPatrolClock() const {
    return patrolClock;
}

void Patrolling::setPatrolClock(const std::shared_ptr<sf::Clock> &patrolClock) {
    Patrolling::patrolClock = patrolClock;
}

Patrolling::Patrolling() {
    patrolClock=std::make_shared<sf::Clock>();
}

Patrolling::~Patrolling() = default;
