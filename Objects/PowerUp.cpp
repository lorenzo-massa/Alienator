//
// Created by Lorenzo Massa on 03/06/2020.
//


#include <SFML/System/Clock.hpp>
#include "PowerUp.h"
#include "../Engine/Game.h"

PowerUp::PowerUp(std::string typeString) {


    type = ERROR;
    if (typeString == "COINS")
        type = COINS;
    else if (typeString == "MUNITIONS")
        type = MUNITIONS;
    else if (typeString == "FIRE_RATE")
        type = FIRE_RATE;
    else if (typeString == "SPEED")
        type = SPEED;
    else if (typeString == "DAMAGE_BOOST")
        type = DAMAGE_BOOST;
    else if (typeString == "INVICIBILITY")
        type = INVICIBILITY;
    else
        std::cerr << "Error loading power up: undefined string: " << typeString << std::endl;

    PowerUp::type = type;
}

PowerUp::PowerUp() {
    type = generateRandom();
}

PowerUp::~PowerUp() {

}

std::string PowerUp::getType() const {
    std::string string;

    if (type == COINS)
        string = "COINS";
    else if ((type == MUNITIONS))
        string = "MUNITIONS";
    else if ((type == FIRE_RATE))
        string = "FIRE_RATE";
    else if ((type == SPEED))
        string = "SPEED";
    else if ((type == DAMAGE_BOOST))
        string = "DAMAGE_BOOST";
    else if ((type == INVICIBILITY))
        string = "INVICIBILITY";
    else
        std::cerr << "Error loading power up" << std::endl;

    return string;
}

PowerUp::TYPE PowerUp::generateRandom() {
    int random = rand() % 6 + 1; //da 1 a 6

    return (enum TYPE) random;
}


