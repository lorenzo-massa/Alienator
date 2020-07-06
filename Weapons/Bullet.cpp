//
// Created by Leonardo Corsini on 27/05/2020.
//


#include <AssetsManager.h>
#include <cmath>
#include "Bullet.h"


Bullet::Bullet(int dam, float x, float y, sf::Vector2f mousePosition):damage(dam),posX(x),posY(y){
    maxSpeed = 15.0f;
    currentSpeed = sf::Vector2f(0,0);

    setTexture(AssetManager::textures.at("Bullet"));
    setPosition(x+32,y+64);
    setScale(sf::Vector2f(0.02f,0.02f));

    sf::Vector2f playerPosition = sf::Vector2f (x, y);
    sf::Vector2f dir = mousePosition - playerPosition;
    sf::Vector2f dirNorm;
    dirNorm.x = dir.x / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
    dirNorm.y = dir.y / sqrt(pow(dir.x, 2) + pow(dir.y, 2));

    int directionX = 0;
    int directionY = 0;

    /*
    std::cout<<"Mouse X: "<<mousePosition.x<<" Y: "<<mousePosition.y<<std::endl;
    std::cout<<"Hero X: "<<playerPosition.x<<" Y: "<<playerPosition.y<<std::endl;
    std::cout<<"Direction X: "<<directionX<<" Y: "<<directionY<<std::endl;
    */

    currentSpeed.x= dirNorm.x * maxSpeed;
    currentSpeed.y= dirNorm.y * maxSpeed;

}

void Bullet::move(float dT) {
    sf::Sprite::move(currentSpeed);
}

float Bullet::getPosY() const {
    return posY;
}
void Bullet::setPosY(int y) {
    posY=y;
}

float Bullet::getPosX() const {
    return posX;
}
void Bullet::setPosX(int x) {
    posX=x;
}

int Bullet::getDamage() const {
    return damage;
}
void Bullet::setDamage(int damage) {
    Bullet::damage = damage;
}

bool Bullet::isFriendly() const {
    return friendly;
}

void Bullet::setFriendly(bool friendly) {
    Bullet::friendly = friendly;
}
