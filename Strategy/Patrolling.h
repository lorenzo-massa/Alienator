//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_PATROLLING_H
#define ALIENATOR_PATROLLING_H


#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>

class Patrolling{
public:
    virtual bool patrol( sf::Vector2f enemyPos,sf::Vector2f heroPos,sf::Vector2f patrolDistance, float &direction) =0;

    const std::shared_ptr<sf::Clock> &getPatrolClock() const;

    void setPatrolClock(const std::shared_ptr<sf::Clock> &patrolClock);

    Patrolling();

    virtual ~Patrolling();
private:
    std::shared_ptr<sf::Clock> patrolClock;

};
#endif //ALIENATOR_PATROLLING_H
