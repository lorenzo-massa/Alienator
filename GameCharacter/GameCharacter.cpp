//
// Created by leoco on 27/05/2020.
//

#include <iostream>
#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int ar, int am, int s) {
    sprite = std::make_shared<sf::Sprite>();
    skin = std::make_shared<sf::Texture>();

}

int GameCharacter::receiveDamage(int points ) {
 //   if (healthPoint>points)
        return healthPoint -= points;
    //else
}
/*
bool GameCharacter::isLegalMovement(int speed,int direction,int posY){
    std::shared_ptr<Map> i;
    i=Game::getGame()->getMapHandler()->getMap();
    char comparison=i->getFromMatrix( posY + posX  + direction * speed);
    char target='B';
    if(comparison == target)
        return false;
    else
        return true;
}*/
void GameCharacter::move(int posX,int posY,int speed,int direction) {
    /*if (isLegalMovement(speed, direction, posY)){
        posX+=speed*direction;
        
    }*/
}


void GameCharacter::jump(int y) {
    y+=50;
}

void GameCharacter::shot(Weapon *weapon) {
    weapon->fire();
}

int GameCharacter::getPosX() const {
    return GameCharacter::posX;
}
void GameCharacter::setPosX(int posX) {
    GameCharacter::posX = posX;
}

int GameCharacter::getPosY() const {
    return GameCharacter::posY;
}

void GameCharacter::setPosY(int posY) {
    GameCharacter::posY = posY;
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

int GameCharacter::getSpeed() const {
    return speed;
}
void GameCharacter::setSpeed(int speed) {
    GameCharacter::speed = speed;
}

int GameCharacter::getAmmo() const {
    return ammo;
}

int GameCharacter::getDirection() const {
    return direction;
}
void GameCharacter::setDirection(int direction) {
    GameCharacter::direction = direction;
}

void GameCharacter::setAmmo(int ammo) {
    GameCharacter::ammo = ammo;
}

GameCharacter::~GameCharacter() {

}


void GameCharacter::init(sf::Vector2f position, sf::Vector2f size){

    if(!skin->loadFromFile("src/Object/Hero.png"))
        std::cerr<<"Error loading Hero skin"<<std::endl;
    else{
        sprite->setTexture(*skin);
        sprite->setPosition(position);
        sprite->setTextureRect(sf::IntRect(0,0,32,64));
    }


}




