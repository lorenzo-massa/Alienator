//
// Created by Leonardo Corsini on 27/05/2020.
//

#include "Enemy.h"


Enemy::Enemy(std::string strBehavior, sf::Vector2f pos,  int hp,sf::Vector2f patrolDistance): behavior(behavior),patrolDistance(patrolDistance),GameCharacter::GameCharacter(hp, 0, 100,sf::Vector2f(0,0),pos,0) {
    if(strBehavior == "Wizard"){
        setTexture(AssetManager::textures.at("Blue_Idle_1"));
        strTexture = "Blue_Idle_1";
        behavior = Wizard();
        patrolDistance.x=64.0f*5.0f;
        patrolDistance.y=64.0f*2.0f;
    } else if (strBehavior == "Sentinel"){
        setTexture(AssetManager::textures.at("Gray_Idle_1"));
        strTexture = "Gray_Idle_1";
        behavior = Sentinel();
        patrolDistance.x=64.0f*7.0f;
        patrolDistance.y=64.0f*2.0f;

    } else {
        setTexture(AssetManager::textures.at("Red_Idle_1"));
        strTexture = "Red_Idle_1";
        behavior = Guard();
        patrolDistance.x=64.0f*4.0f;
        patrolDistance.y=64.0f*2.0f;
    }
    setPosition(pos);
    setTextureRect(sf::IntRect(0,0,213.0f,428.0f));
    setScale(sf::Vector2f(0.25f,0.25f));
}

Enemy::~Enemy() {}

sf::Vector2f Enemy::move(sf::Vector2f direction, float deltaT) {
    return GameCharacter::move(direction, deltaT);
}

std::shared_ptr<Bullet> Enemy::shot(sf::Vector2f mousePosition) {
    return GameCharacter::shot(mousePosition);
}

bool Enemy::patrol(float deltaT, float directionX,sf::Sprite hero,sf::Vector2f* move) {


        bool found=false;

        if(directionX>0){
            if( hero.getPosition().x<patrolDistance.x) {
                if( hero.getPosition().y>patrolDistance.y){
                found = true;
                return found;
                }
            }
        }
        else
        if( hero.getPosition().x>-1*patrolDistance.x){
            if( hero.getPosition().y>patrolDistance.y)
            {
                found=true;
                return found;
            }
        }

            *move = Enemy::move(sf::Vector2f(directionX, 1.0f), deltaT);

        return found;

}

bool Enemy::fight(bool found,sf::Sprite hero,sf::Vector2f* move,float deltaT,std::shared_ptr<Bullet>* b/*,bool collision*/) {

    bool shot= false;
    if(found){

        if(hero.getPosition().x<Enemy::getPosition().x){
            *move = Enemy::move(sf::Vector2f(-1.0f, 1.0f), deltaT);
            *b=Enemy::shot(hero.getPosition());
            shot=true;
        }
        else{
            *move = Enemy::move(sf::Vector2f(1.0f, 1.0f), deltaT);
            *b=Enemy::shot(hero.getPosition());
            shot=true;
        }
        if(hero.getPosition().y<Enemy::getPosition().y){
           /* if(collision){
                Enemy::jump();
            }*/
        }
    }

    return shot;
}
