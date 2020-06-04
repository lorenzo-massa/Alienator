//
// Created by leoco on 27/05/2020.
//

#include <iostream>
#include <AssetsManager.h>
#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int ar, int am,sf::Vector2f s) :healthPoint(hp),armor(ar),ammo(am),speed(s){
    sprite = std::make_shared<sf::Sprite>();
    skin = std::make_shared<sf::Texture>();

}
GameCharacter::GameCharacter(sf::Vector2f pos) :pos(pos){}

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
void GameCharacter::move(sf::Vector2f direction) {

    GameCharacter::getSprite()->move(direction.x *5.0f,direction.y*1.0f );

}


float GameCharacter::jump() {
    float j;
    j-=50;
    return j;
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

GameCharacter::~GameCharacter() {

}


void GameCharacter::init(sf::Vector2f position, sf::Vector2f size){


    sprite->setTexture(AssetManager::textures.at("HERO"));
    sprite->setPosition(position);
    sprite->setTextureRect(sf::IntRect(0,0,32,64));
    sprite->setScale(size);

}




