//
// Created by leoco on 10/07/2020.
//

#ifndef ALIENATOR_PATROLBEHAVIOR_H
#define ALIENATOR_PATROLBEHAVIOR_H


#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>

#define BLOCK_SIZE 64

class PatrolBehavior{
public:
    virtual bool patrol( sf::Vector2f enemyPos,sf::Vector2f heroPos,sf::Vector2f patrolDistance, float &direction) =0;

    const std::shared_ptr<sf::Clock> &getPatrolClock() const;

    void setPatrolClock(const std::shared_ptr<sf::Clock> &patrolClock);

    PatrolBehavior();

    virtual ~PatrolBehavior();
private:
    std::shared_ptr<sf::Clock> patrolClock;

};
#endif //ALIENATOR_PATROLBEHAVIOR_H
