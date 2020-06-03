//
// Created by Lorenzo Massa on 03/06/2020.
//


#include "PowerUp.h"

PowerUp::PowerUp(std::string typeString){
    type = ERROR;
    if(typeString == "COINS")
        type = COINS;
    else if(typeString == "MUNITIONS")
        type = MUNITIONS;
    else if(typeString == "FIRE_RATE")
        type = FIRE_RATE;
    else if(typeString == "SPEED")
        type = SPEED;
    else if(typeString == "DAMAGE_BOOST")
        type = DAMAGE_BOOST;
    else if(typeString == "INVICIBILITY")
        type = INVICIBILITY;
    else
        std::cerr<<"Error loading power up: undefined string: "<<typeString<<std::endl;

    PowerUp::type = type;
}

PowerUp::PowerUp() {
    type = generateRandom();
}

PowerUp::~PowerUp() {

}

const PowerUp::TYPE &PowerUp::getType() const {
    return type;
}

PowerUp::TYPE PowerUp::generateRandom() {

    srand (time(NULL));
    int random = rand() % 6 + 1; //da 1 a 6

    return (enum TYPE)random;
}


