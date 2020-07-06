//
// Created by Leonardo Corsini on 27/05/2020.
//


#include <AssetsManager.h>
#include <cmath>
#include "Bullet.h"


Bullet::Bullet(int dam, float x, float y, sf::Vector2f mousePosition):damage(dam),posX(x),posY(y), friendly(false){
    maxSpeed = 18.0f;
    currentSpeed = sf::Vector2f(0,0);

    setTexture(AssetManager::textures.at("Bullet"));
    setPosition(x+32,y+64);
    setScale(sf::Vector2f(0.02f,0.02f));

    sf::Vector2f playerPosition = sf::Vector2f (x, y);
    sf::Vector2f dir = mousePosition - playerPosition;
    sf::Vector2f dirNorm;
    dirNorm.x = dir.x / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
    dirNorm.y = dir.y / sqrt(pow(dir.x, 2) + pow(dir.y, 2));

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

void Bullet::setPosX1(float posX) {
    Bullet::posX = posX;
}

void Bullet::setPosY1(float posY) {
    Bullet::posY = posY;
}

const sf::Vector2f &Bullet::getCurrentSpeed() const {
    return currentSpeed;
}

void Bullet::setCurrentSpeed(const sf::Vector2f &currentSpeed) {
    Bullet::currentSpeed = currentSpeed;
}

float Bullet::getMaxSpeed() const {
    return maxSpeed;
}

void Bullet::setMaxSpeed(float maxSpeed) {
    Bullet::maxSpeed = maxSpeed;
}
