//
// Created by leoco on 10/07/2020.
//

#include <SFML/System/Vector2.hpp>
#include "GroundPatrolling.h"

bool GroundPatrolling::patrol(float deltaT, sf::Vector2f enemyPos,sf::Vector2f heroPos,sf::Vector2f patrolDistance, float direction) {

    bool found = false;

    if (direction > 0) {

        if (heroPos.x > enemyPos.x && enemyPos.x + patrolDistance.x > heroPos.x) {
            if ((heroPos.y <= enemyPos.y &&
                 heroPos.y > enemyPos.y - patrolDistance.y) ||
                (heroPos.y >= enemyPos.y &&
                 heroPos.y < enemyPos.y + patrolDistance.y)) {
                found = true;
                return found;
            }
        }
    } else if (direction < 0) {
        if (heroPos.x < enemyPos.x && heroPos.x > enemyPos.x - patrolDistance.x) {
            if ((heroPos.y <= enemyPos.y &&
                 heroPos.y > enemyPos.y - patrolDistance.y) ||
                (heroPos.y >= enemyPos.y &&
                 heroPos.y < enemyPos.y + patrolDistance.y)) {
                found = true;
                return found;
            }
        }
    }
}
