//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_ENEMY_H
#define ALIENATOR_ENEMY_H

#include "GameCharacter.h"
#include "EnemyBehavior/EnemyBehavior.h"

class Enemy : virtual public GameCharacter{
public:
    Enemy(EnemyBehavior behavior, sf::Vector2f pos,  int hp);
    ~Enemy();

private:
    EnemyBehavior behavior;
};

#endif //ALIENATOR_ENEMY_H
