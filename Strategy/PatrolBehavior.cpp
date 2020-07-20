//
// Created by leoco on 10/07/2020.
//

#include "PatrolBehavior.h"

const std::shared_ptr<sf::Clock> &PatrolBehavior::getPatrolClock() const {
    return patrolClock;
}

void PatrolBehavior::setPatrolClock(const std::shared_ptr<sf::Clock> &patrolClock) {
    PatrolBehavior::patrolClock = patrolClock;
}

PatrolBehavior::PatrolBehavior() {
    patrolClock=std::make_shared<sf::Clock>();
}

PatrolBehavior::~PatrolBehavior() = default;
