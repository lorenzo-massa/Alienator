//
// Created by Leonardo Corsini on 27/05/2020.
//

#include "Enemy.h"
#include "../Strategy/ConcreteStrategy/GroundPatrolling.h"
#include "../Strategy/ConcreteStrategy/CloseAttack.h"
#include "../Strategy/ConcreteStrategy/DistanceAttack.h"


Enemy::Enemy(std::string strBehavior, sf::Vector2f pos, int hp, int armor, sf::Vector2f(speed), float speedCoeff,
             sf::Vector2f patrolDistance, std::string behavior) : patrolDistance(patrolDistance),
                                                                  GameCharacter::GameCharacter(hp, armor, 100, speed,
                                                                                               pos, sf::Vector2f(1.0f,1.0f), speedCoeff),
                                                                                               behavior(behavior) {
   float fr,dm;
    if (strBehavior == "Wizard") {
        setTexture(AssetManager::getAssetManager()->getTextures().at("Blue_Idle_1"));
        strTexture = "Blue_Idle_1";
        fr=1.0f;
        dm=250.0f;
       patroller=std::make_shared<GroundPatrolling>();
       attacker=std::make_shared<CloseAttack>();

    } else if (strBehavior == "Sentinel") {
        setTexture(AssetManager::getAssetManager()->getTextures().at("Gray_Idle_1"));
        strTexture = "Gray_Idle_1";
        fr=0.5f;
        dm=800.0f;
        patroller=std::make_shared<GroundPatrolling>();
        attacker=std::make_shared<DistanceAttack>();

    } else {
        setTexture(AssetManager::getAssetManager()->getTextures().at("Red_Idle_1"));
        strTexture = "Red_Idle_1";
        fr=3;
        dm=100.0f;
        patroller=std::make_shared<GroundPatrolling>();
        attacker=std::make_shared<CloseAttack>();

    }
    weapon = std::make_shared<Weapon>(dm, fr);
    behaviorType = strBehavior;
    setPosition(pos);
    setTextureRect(sf::IntRect(0, 0, 213.0f, 428.0f));
    setScale(sf::Vector2f(0.25f, 0.25f));

    //clockPatrol = std::make_shared<sf::Clock>();
}

Enemy::~Enemy() {}

sf::Vector2f Enemy::move( float deltaT) {
    return GameCharacter::move( deltaT);
}

std::shared_ptr<Bullet> Enemy::shot(sf::Vector2f mousePosition) {
    return GameCharacter::shot(mousePosition);
}

/*bool Enemy::patrol(float deltaT, sf::Vector2f heroPos, sf::Vector2f *move) {

    bool found = false;

    if (Enemy::getDirection() > 0) {

        if (heroPos.x > sf::Sprite::getPosition().x && sf::Sprite::getPosition().x + patrolDistance.x > heroPos.x) {
            if ((heroPos.y <= sf::Sprite::getPosition().y &&
                 heroPos.y > sf::Sprite::getPosition().y - patrolDistance.y) ||
                (heroPos.y >= sf::Sprite::getPosition().y &&
                 heroPos.y < sf::Sprite::getPosition().y + patrolDistance.y)) {
                found = true;
                return found;
            }
        }
    } else if (Enemy::getDirection() < 0) {
        if (heroPos.x < sf::Sprite::getPosition().x && heroPos.x > sf::Sprite::getPosition().x - patrolDistance.x) {
            if ((heroPos.y <= sf::Sprite::getPosition().y &&heroPos.y > sf::Sprite::getPosition().y - patrolDistance.y) ||
                (heroPos.y >= sf::Sprite::getPosition().y &&heroPos.y < sf::Sprite::getPosition().y + patrolDistance.y)) {
                found = true;
                return found;
            }
        }
    }

    move->x = Enemy::move( deltaT).x;
    move->y = Enemy::move( deltaT).y;


    return found;

}

std::shared_ptr<Bullet> Enemy::fight(sf::Vector2f heroPos, sf::Vector2f &move, float deltaT) {

    std::shared_ptr<Bullet> b;

    if (heroPos.x < Enemy::getPosition().x) {

        Enemy::setDirection(-1.0f);
        move.x = Enemy::move( deltaT).x;
        move.y = Enemy::move( deltaT).y;
        if(std::abs(heroPos.x-Enemy::getPosition().x)<128.0f){
            move.x=0;
        }

        b = Enemy::shot(heroPos);

    }
    else{
        Enemy::setDirection(1.0f);
        move.x = Enemy::move( deltaT).x;
        move.y = Enemy::move( deltaT).y;
        if(std::abs(heroPos.x-Enemy::getPosition().x)<128.0f){
            move.x=0;
        }

        b = Enemy::shot(heroPos);
    }
    if (heroPos.y < Enemy::getPosition().y) {
             if(collision){
             Enemy::jump();
         }
    }
    return b;
}
*/
bool Enemy::checkJump() {
    return getSpeed() == sf::Vector2f(0, 0);
}

const std::string &Enemy::getBehavior() const {
    return behavior;
}

void Enemy::setBehavior(const std::string &behavior) {
    Enemy::behavior = behavior;
}

const std::string &Enemy::getBehaviorType() const {
    return behaviorType;
}

void Enemy::setBehaviorType(const std::string &behaviorType) {
    Enemy::behaviorType = behaviorType;
}

const sf::Vector2f &Enemy::getPatrolDistance() const {
    return patrolDistance;
}

void Enemy::setPatrolDistance(const sf::Vector2f &patrolDistance) {
    Enemy::patrolDistance = patrolDistance;
}

/*const std::shared_ptr<sf::Clock> &Enemy::getClockPatrol() const {
    return clockPatrol;
}

void Enemy::setClockPatrol(const std::shared_ptr<sf::Clock> &clockPatrol) {
    Enemy::clockPatrol = clockPatrol;
}
*/
bool Enemy::patrolling(sf::Vector2f heroPos,sf::Vector2f &move,float deltaT) {

    bool found;
    sf::Vector2f dir=Enemy::getDirection();
    found=Enemy::getPatroller()->patrol(Enemy::getPosition(),heroPos,Enemy::getPatrolDistance(),dir.x);
    Enemy::setDirection(dir);
    move = Enemy::move( deltaT);

    return found;
}

std::shared_ptr<Bullet> Enemy::fighting(sf::Vector2f heroPos,sf::Vector2f &move,float deltaT) {

    std::shared_ptr<Bullet> b;
    sf::Vector2f dir=Enemy::getDirection();

    move=Enemy::move(deltaT);
    Enemy::getAttacker()->attack(heroPos,Enemy::getPosition(),move,dir.x);
    Enemy::setDirection(dir);
    b=Enemy::shot(heroPos);

    return b;

}

const std::shared_ptr<Patrolling> &Enemy::getPatroller() const {
    return patroller;
}

void Enemy::setPatroller(const std::shared_ptr<Patrolling> &patroller) {
    Enemy::patroller = patroller;
}

const std::shared_ptr<Attack> &Enemy::getAttacker() const {
    return attacker;
}

void Enemy::setAttacker(const std::shared_ptr<Attack> &attacker) {
    Enemy::attacker = attacker;
}
