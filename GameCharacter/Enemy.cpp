//
// Created by Leonardo Corsini on 27/05/2020.
//

#include "Enemy.h"
#include "../Strategy/ConcreteStrategy/GroundPatrolling.h"
#include "../Strategy/ConcreteStrategy/CloseAttack.h"
#include "../Strategy/ConcreteStrategy/DistanceAttack.h"


Enemy::Enemy(EnemyType typeBehavior, sf::Vector2f pos, int hp, int armor, sf::Vector2f(speed), float speedCoeff,
             sf::Vector2f patrolDistance, TypeBehavior behavior) : patrolDistance(patrolDistance),
                                                                  GameCharacter::GameCharacter(hp, armor, 100, speed,
                                                                                               pos, sf::Vector2f(1.0f,1.0f), speedCoeff),
                                                                                               behavior(behavior) {
   float fr,dm;
    if (typeBehavior == EnemyType::Wizard) {
        setTexture(AssetManager::getAssetManager()->getTextures().at("Blue_Idle_1"));
        strTexture = "Blue_Idle_1";
        fr=1.0f;
        dm=250.0f;
       patroller=std::make_shared<GroundPatrolling>();
       attacker=std::make_shared<CloseAttack>();

    } else if (typeBehavior == EnemyType::Sentinel) {
        setTexture(AssetManager::getAssetManager()->getTextures().at("Gray_Idle_1"));
        strTexture = "Gray_Idle_1";
        fr=0.5f;
        dm=800.0f;
        patroller=std::make_shared<GroundPatrolling>();
        attacker=std::make_shared<DistanceAttack>();

    } else if (typeBehavior == EnemyType::Guard){
        setTexture(AssetManager::getAssetManager()->getTextures().at("Red_Idle_1"));
        strTexture = "Red_Idle_1";
        fr=3;
        dm=100.0f;
        patroller=std::make_shared<GroundPatrolling>();
        attacker=std::make_shared<CloseAttack>();

    }
    weapon = std::make_shared<Weapon>(dm, fr);
    behaviorType = typeBehavior;
    setPosition(pos);
    setTextureRect(sf::IntRect(0, 0, 213.0f, 428.0f));
    setScale(sf::Vector2f(0.25f, 0.25f));

}

Enemy::~Enemy() = default;

sf::Vector2f Enemy::move( float deltaT) {
    return GameCharacter::move( deltaT);
}

std::shared_ptr<Bullet> Enemy::shot(sf::Vector2f mousePosition) {
    return GameCharacter::shot(mousePosition);
}

bool Enemy::checkJump() {
    return getSpeed() == sf::Vector2f(0, 0);
}

const TypeBehavior &Enemy::getBehavior() const {
    return behavior;
}

void Enemy::setBehavior(const TypeBehavior &behavior) {
    Enemy::behavior = behavior;
}

const EnemyType &Enemy::getBehaviorType() const {
    return behaviorType;
}

void Enemy::setBehaviorType(const EnemyType &behaviorType) {
    Enemy::behaviorType = behaviorType;
}

const sf::Vector2f &Enemy::getPatrolDistance() const {
    return patrolDistance;
}

void Enemy::setPatrolDistance(const sf::Vector2f &patrolDistance) {
    Enemy::patrolDistance = patrolDistance;
}

bool Enemy::patrolling(sf::Vector2f heroPos,sf::Vector2f &move,float deltaT) {

    bool found;
    sf::Vector2f dir=direction;
    found=patroller->patrol(getPosition(),heroPos,patrolDistance,dir.x);
    direction = dir;
    move = Enemy::move(deltaT);

    return found;
}

std::shared_ptr<Bullet> Enemy::fighting(sf::Vector2f heroPos,sf::Vector2f &move,float deltaT) {

    std::shared_ptr<Bullet> b;
    sf::Vector2f dir=direction;

    move=Enemy::move(deltaT);
    attacker->attack(heroPos,Enemy::getPosition(),move,dir.x);
    direction = dir;
    b=shot(heroPos);

    return b;

}

const std::shared_ptr<PatrolBehavior> &Enemy::getPatroller() const {
    return patroller;
}

void Enemy::setPatroller(const std::shared_ptr<PatrolBehavior> &patroller) {
    Enemy::patroller = patroller;
}

const std::shared_ptr<AttackBehavior> &Enemy::getAttacker() const {
    return attacker;
}

void Enemy::setAttacker(const std::shared_ptr<AttackBehavior> &attacker) {
    Enemy::attacker = attacker;
}
