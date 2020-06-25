//
// Created by leoco on 27/05/2020.
//

#include <SFML/System/Vector2.hpp>
#include "EnemyBehavior.h"


bool EnemyBehavior::patrol(sf::Sprite hero,sf::Sprite enemy ,float deltaT,float directionX) {
    sf::Vector2f move;
    bool found=false;
    //move=enemy.move(sf::Vector2f(directionX,1.0f),deltaT);
    if(directionX>0){
        if( hero.getPosition().x<move.x+30.0f*64.0f) {
            found = true;
            return found;
        }
    }
    else
        if( hero.getPosition().x>-1*move.x+30.0f*64.0f)
        {
            found=true;
            return found;
        }

    //sf::Sprite move(sf::Vector2f(move));
    return found;
}

void EnemyBehavior::fight() {

}

