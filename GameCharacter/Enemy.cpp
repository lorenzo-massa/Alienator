//
// Created by Leonardo Corsini on 27/05/2020.
//

#include "Enemy.h"


Enemy::Enemy(std::string strBehavior, sf::Vector2f pos,  int hp): behavior(behavior),GameCharacter::GameCharacter(hp, 0, 100,sf::Vector2f(0,0),pos,0) {
    if(strBehavior == "Wizard"){
        setTexture(AssetManager::textures.at("Blue_Idle_1"));
        strTexture = "Blue_Idle_1";
        behavior = Wizard();
    } else if (strBehavior == "Sentinel"){
        setTexture(AssetManager::textures.at("Gray_Idle_1"));
        strTexture = "Gray_Idle_1";
        behavior = Sentinel();

    } else {
        setTexture(AssetManager::textures.at("Red_Idle_1"));
        strTexture = "Red_Idle_1";
        behavior = Guard();
    }
    setPosition(pos);
    setTextureRect(sf::IntRect(0,0,213.0f,428.0f));
    setScale(sf::Vector2f(0.25f,0.25f));
}

Enemy::~Enemy() {}
