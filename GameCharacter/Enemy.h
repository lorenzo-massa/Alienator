//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_ENEMY_H
#define ALIENATOR_ENEMY_H

#include "GameCharacter.h"
#include "EnemyTypeEnum.h"
#include <AssetsManager.h>
#include "../Strategy/Patrolling.h"
#include "../Strategy/Attack.h"
#include "../Strategy/BehaviorEnum.h"


class Enemy : virtual public GameCharacter {
public:
    Enemy(EnemyType typeBehavior, sf::Vector2f pos, int hp, int armor, sf::Vector2f(speed), float speedCoeff,
          sf::Vector2f patrolDistance, TypeBehavior behavior);

    ~Enemy() override;

    sf::Vector2f move( float deltaT) override;

    std::shared_ptr<Bullet> shot(sf::Vector2f mousePosition) override;

    const TypeBehavior &getBehavior() const;

    void setBehavior(const TypeBehavior &behavior);

    const EnemyType &getBehaviorType() const;

    void setBehaviorType(const EnemyType &behaviorType);

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
    TypeBehavior behavior;

    EnemyType behaviorType;

    sf::Vector2f patrolDistance;

    std::shared_ptr<Patrolling> patroller;

    std::shared_ptr<Attack> attacker;

};

#endif //ALIENATOR_ENEMY_H
