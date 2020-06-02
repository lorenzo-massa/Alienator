//
// Created by leoco on 27/05/2020.
//

#include "Hero.h"

Hero::Hero(int hp, int ar, int am, int s) : GameCharacter(hp, ar, am, s) {

}

Hero::~Hero() {

}

int Hero::getCoins() const {
    return coins;
}
void Hero::setCoins(int coins) {
    Hero::coins = coins;
}

