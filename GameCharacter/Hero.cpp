//
// Created by leoco on 27/05/2020.
//

#include "Hero.h"

Hero::Hero(int hp, int ar, int am, sf::Vector2f s,sf::Vector2f pos,float dir, int coins) : GameCharacter(hp, ar, am, s,pos,dir), coins(coins) {}
Hero::~Hero() {}

int Hero::getCoins() const {
    return coins;
}
void Hero::setCoins(int coins) {
    Hero::coins = coins;
}

void Hero::shot(Weapon *weapon) {
    GameCharacter::shot(weapon);
}

sf::Vector2f Hero::move(sf:: Vector2f direction, float deltaT) {
    return GameCharacter::move(direction,deltaT);
}

void Hero::jump() {
    GameCharacter::jump();
}

int Hero::receiveDamage(int points) {
    return GameCharacter::receiveDamage(points);
}

void Hero::moveSfml(float x,float y){
    GameCharacter::moveSfml(x,y);
}

Hero::Hero() {

}

/*bool Hero::isLegalMovement(char comparison) {
    return GameCharacter::isLegalMovement(comparison);
}*/

