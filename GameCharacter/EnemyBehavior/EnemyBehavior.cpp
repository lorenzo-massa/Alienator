//
// Created by leoco on 27/05/2020.
//

#include <SFML/System/Vector2.hpp>
#include "EnemyBehavior.h"


bool EnemyBehavior::patrol(sf::Sprite hero,sf::Sprite enemy ,float deltaT,float directionX) {//TODO inserire in enemy un patrolDistance
    sf::Vector2f move;
    bool found=false;
    //move=enemy.move(sf::Vector2f(directionX,1.0f),deltaT);
    if(directionX>0){
        if( hero.getPosition().x<move.x/*+patrolDistance*/) {
            found = true;
            return found;
        }
    }
    else
        if( hero.getPosition().x>-1*move.x/*+patrolDistance*/){
            found=true;
            return found;
        }
    return found;
}

void EnemyBehavior::fight(/*bool found*/) {
//    if(/*found*/)
    {
        //enemy.shot;
        float direction;//se posX di hero< posX di enemy direction=-1, in caso contrario directio=1
        //if()
        //{
            //direction=;
        //}
        //enemy.move(sf::Vector2f(direction,1)(passare dt))
        //implementare controllo per passare il behavior
        //saltare se trova un ostacolo

    }
}

