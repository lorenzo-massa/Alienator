//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_ENEMY_H
#define ALIENATOR_ENEMY_H

#include "GameCharacter.h"
#include "EnemyBehavior/EnemyBehavior.h"
#include "EnemyBehavior/Wizard.h"
#include "EnemyBehavior/Sentinel.h"
#include "EnemyBehavior/Guard.h"
#include <AssetsManager.h>

class Enemy : virtual public GameCharacter{
public:
    Enemy(std::string strBehavior, sf::Vector2f pos,  int hp, int armor,sf::Vector2f patrolDistance);
    ~Enemy();

    sf::Vector2f move(sf::Vector2f direction, float deltaT) override;
    std::shared_ptr<Bullet> shot(sf::Vector2f mousePosition) override;
    bool patrol(float deltaT, float directionX,sf::Vector2f heroPos,sf::Vector2f* move);
    std::shared_ptr<Bullet> fight(bool found,sf::Vector2f heroPos,sf::Vector2f* move,float deltaT,std::shared_ptr<Bullet> b/*,bool collision*/);

private:
    EnemyBehavior behavior;
    sf::Vector2f patrolDistance;
};

#endif //ALIENATOR_ENEMY_H
