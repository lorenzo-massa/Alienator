//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_ENEMY_H
#define ALIENATOR_ENEMY_H

#include "GameCharacter.h"
#include <AssetsManager.h>
#include "../Behavior/Strategy/Patrolling.h"
#include "../Behavior/Strategy/Attack.h"


class Enemy : virtual public GameCharacter {
public:
    Enemy(std::string strBehavior, sf::Vector2f pos, int hp, int armor, sf::Vector2f(speed), float speedCoeff,
          sf::Vector2f patrolDistance, std::string behavior);

    ~Enemy() override;

    sf::Vector2f move( float deltaT) override;

    std::shared_ptr<Bullet> shot(sf::Vector2f mousePosition) override;

    const std::string &getBehavior() const;

    void setBehavior(const std::string &behavior);

    const std::string &getBehaviorType() const;

    void setBehaviorType(const std::string &behaviorType);

    const sf::Vector2f &getPatrolDistance() const;


    void setPatrolDistance(const sf::Vector2f &patrolDistance);

    bool checkJump();

    bool patrolling(sf::Vector2f heroPos,sf::Vector2f &move,float deltaT);

    std::shared_ptr<Bullet> fighting(sf::Vector2f heroPos,sf::Vector2f &move,float deltaT);

    const std::shared_ptr<Patrolling> &getPatroller() const;

    void setPatroller(const std::shared_ptr<Patrolling> &patroller);

    const std::shared_ptr<Attack> &getAttacker() const;

    void setAttacker(const std::shared_ptr<Attack> &attacker);

private:
    std::string behavior;

    std::string behaviorType;

    sf::Vector2f patrolDistance;

    std::shared_ptr<Patrolling> patroller;

    std::shared_ptr<Attack> attacker;

};

#endif //ALIENATOR_ENEMY_H
