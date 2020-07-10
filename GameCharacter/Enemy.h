//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_ENEMY_H
#define ALIENATOR_ENEMY_H

#include "GameCharacter.h"
#include <AssetsManager.h>

class Enemy : virtual public GameCharacter {
public:
    Enemy(std::string strBehavior, sf::Vector2f pos, int hp, int armor, sf::Vector2f(speed), float speedCoeff,
          sf::Vector2f patrolDistance, std::string behavior);

    ~Enemy();

    sf::Vector2f move( float deltaT) override;

    std::shared_ptr<Bullet> shot(sf::Vector2f mousePosition) override;

    bool patrol(float deltaT, float directionX, sf::Vector2f heroPos, sf::Vector2f *move);

    std::shared_ptr<Bullet> fight(sf::Vector2f heroPos, sf::Vector2f &move, float deltaT);

    const std::string &getBehavior() const;

    void setBehavior(const std::string &behavior);

    const std::string &getBehaviorType() const;

    void setBehaviorType(const std::string &behaviorType);

    const sf::Vector2f &getPatrolDistance() const;

    const std::shared_ptr<sf::Clock> &getClockPatrol() const;

    void setClockPatrol(const std::shared_ptr<sf::Clock> &clockPatrol);

    void setPatrolDistance(const sf::Vector2f &patrolDistance);

    bool checkJump();


private:
    std::string behavior;

    std::string behaviorType;

    sf::Vector2f patrolDistance;

    std::shared_ptr<sf::Clock> clockPatrol;
};

#endif //ALIENATOR_ENEMY_H
