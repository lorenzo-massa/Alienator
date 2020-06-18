//
// Created by Leonardo Corsini on 27/05/2020.
//

#include <AssetsManager.h>
#include "Enemy.h"

Enemy::Enemy(EnemyBehavior behavior, sf::Vector2f pos,  int hp): behavior(behavior),GameCharacter::GameCharacter(hp, 0, 100,sf::Vector2f(0,0),pos,0) {
    setTexture(AssetManager::textures.at("Blue_Idle_1"));
    strTexture = "Ble_Idle_1";
    setPosition(pos);
    setTextureRect(sf::IntRect(0,0,213.0f,428.0f));
    setScale(sf::Vector2f(0.25f,0.25f));
}

Enemy::~Enemy() {}
