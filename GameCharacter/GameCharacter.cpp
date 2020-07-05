//
// Created by Leonardo Corsini on 27/05/2020.
//

#include <AssetsManager.h>
#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int ar, int am,sf::Vector2f s,sf::Vector2f pos,float dir) :
healthPoint(hp),armor(ar),ammo(am),speed(s),pos(pos),direction(dir),speedBoost(1.0f),invincibility(false),fireRateBoost(1.0f),damageBoost(1.0f){}

int GameCharacter::receiveDamage(int points ) {
    if(!invincibility)
        healthPoint -= (points/armor);

        return (points/armor);
}

sf::Vector2f GameCharacter::move(sf::Vector2f direction,float deltaT) {
    float yT;
    float xT;

   if(direction.x==0.0f) {   //attrito
        if (speed.x > 0)
            speed.x -= 30.0f * 64.0f * deltaT;
        else if (speed.x<0)
            speed.x += 30.0f * 64.0f * deltaT;

        if(speed.x>-3 && speed.x<3)//settaggio velocità
            speed.x=0;
    }
    if(direction.x!=0)
        speed.x=10.0f*64.0f*direction.x;//velocità costante se tengo premuto

    xT=speed.x*deltaT;

    speed.y=speed.y+98.0f*64.0f*deltaT; //gravità
    yT=(speed.y*deltaT+0.5f*98.0f*64.0f*deltaT*deltaT)*direction.y;

    xT = xT*speedBoost;
    yT = yT*speedBoost;

    return sf::Vector2f(xT,yT);
}


void GameCharacter::jump() {
    speed.y-=25.0f*64.0f;
}

void GameCharacter::shot(Weapon *weapon) {
    weapon->fire();
}

//Getter e Setter
sf::Vector2f GameCharacter::getPos() const {
    return GameCharacter::pos;
}
void GameCharacter::setPos(sf::Vector2f pos) {
    GameCharacter::pos = pos;
}

int GameCharacter::getHealthPoint() const {
    return GameCharacter::healthPoint;
}
void GameCharacter::setHealthPoint(int healthPoint) {
    GameCharacter::healthPoint=healthPoint;
}

Weapon *GameCharacter::getWeapon() {
    return weapon;
}
void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon=weapon;
}

int GameCharacter::getArmor() const {
    return armor;
}
void GameCharacter::setArmor(int armor) {
    GameCharacter::armor = armor;
}

sf::Vector2f GameCharacter::getSpeed() const {
    return speed;
}
void GameCharacter::setSpeed(sf::Vector2f speed) {
    GameCharacter::speed = speed;
}

int GameCharacter::getAmmo() const {
    return ammo;
}

void GameCharacter::setAmmo(int ammo) {
    GameCharacter::ammo = ammo;
}

float GameCharacter::getDirection() const {
    return direction;
}

void GameCharacter::setDirection(float direction) {
    GameCharacter::direction = direction;
}
GameCharacter::~GameCharacter() {

}

GameCharacter::GameCharacter() {

}

const std::string &GameCharacter::getStrTexture() const {
    return strTexture;
}

void GameCharacter::setStrTexture(const std::string &strTexture) {
    GameCharacter::strTexture = strTexture;
}

float GameCharacter::getSpeedBoost() const {
    return speedBoost;
}

void GameCharacter::setSpeedBoost(float speedBoost) {
    GameCharacter::speedBoost = speedBoost;
}

bool GameCharacter::isInvincibility() const {
    return invincibility;
}

void GameCharacter::setInvincibility(bool invincibility) {
    GameCharacter::invincibility = invincibility;
}

const sf::Clock &GameCharacter::getClockPowerUp() const {
    return clockPowerUp;
}

void GameCharacter::setClockPowerUp(const sf::Clock &clockPowerUp) {
    GameCharacter::clockPowerUp = clockPowerUp;
}

bool GameCharacter::isPowerUpState() const {
    return powerUpState;
}

void GameCharacter::setPowerUpState(bool powerUpState) {
    GameCharacter::powerUpState = powerUpState;
}

float GameCharacter::getFireRateBoost() const {
    return fireRateBoost;
}

void GameCharacter::setFireRateBoost(float fireRateBoost) {
    GameCharacter::fireRateBoost = fireRateBoost;
}

float GameCharacter::getDamageBoost() const {
    return damageBoost;
}

void GameCharacter::setDamageBoost(float damageBoost) {
    GameCharacter::damageBoost = damageBoost;
}

void GameCharacter::resetClockPowerUp() {
    clockPowerUp.restart();
}

void GameCharacter::removePowerUp() {
    invincibility = false;
    speedBoost = 1.0f;
    fireRateBoost = 1.0f;
    damageBoost = 1.0f;

    powerUpState = false;
    std::cout<<"Power Up removed!"<<std::endl;
}







