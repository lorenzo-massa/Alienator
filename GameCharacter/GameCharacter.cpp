//
// Created by Leonardo Corsini on 27/05/2020.
//

#include <iostream>
#include <AssetsManager.h>
#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int ar, int am,sf::Vector2f s,sf::Vector2f pos,float dir) :sf::Sprite(AssetManager::textures.at("HERO")),healthPoint(hp),armor(ar),ammo(am),speed(s),pos(pos),direction(dir){
    setTextureRect(sf::IntRect(0,0,16,128));
    init(pos,sf::Vector2f(2,2));
}




int GameCharacter::receiveDamage(int points ) {
 //   if (healthPoint>points)
        return healthPoint -= points;
    //else
}

/*bool GameCharacter::isLegalMovement(char comparison){

    char target = 'B';
    if(comparison == target)
        return true;
    else
        return false;
}*/
void GameCharacter::move(sf::Vector2f direction,float deltaT) {
    float yT;
    float xT;
    speed.y=speed.y+98.0*64*deltaT;
    if(direction.x==0) {
        if (speed.x > 0)
            speed.x -= 30 * 64 * deltaT;
        else if (speed.x<0)
            speed.x += 30 * 64 * deltaT;
    }
   if(speed.x>-5 && speed.x<5)
       speed.x=0;

    if(direction.x!=0)
        speed.x=8*64*direction.x;

    xT=speed.x*deltaT;
    yT=speed.y*deltaT+0.5*98.0*64.0*deltaT*deltaT;
    sf::Sprite::move(xT,direction.y*yT);

}


void GameCharacter::jump() {
    speed.y-=50.0*64.0;

}

void GameCharacter::shot(Weapon *weapon) {
    weapon->fire();
}

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


void GameCharacter::init(sf::Vector2f position, sf::Vector2f size){

    setTexture(AssetManager::textures.at("HERO"));
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,32,64));
    setScale(size);

}






