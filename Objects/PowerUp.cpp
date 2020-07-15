//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "PowerUp.h"

PowerUp::PowerUp(TYPE t): type(t) {
}

PowerUp::PowerUp() {
    type = generateRandom();
}

PowerUp::~PowerUp() {
}

PowerUp::TYPE PowerUp::generateRandom() {
    int random = rand() % 6 + 1; //da 1 a 6

    return (enum TYPE) random;
}

void PowerUp::setType(PowerUp::TYPE type) {
    PowerUp::type = type;
}

PowerUp::TYPE PowerUp::getType() const {
    return type;
}

std::string PowerUp::typeToString() const {
    std::string result;

    switch (type) {
        case TYPE::COINS:
            result = "COINS";
            break;
        case TYPE::DAMAGE_BOOST:
            result = "DAMAGE_BOOST";
            break;
        case TYPE::FIRE_RATE:
            result = "FIRE_RATE";
            break;
        case TYPE::INVINCIBILITY:
            result = "INVICIBILITY";
            break;
        case TYPE::MUNITIONS:
            result = "MUNITIONS";
            break;
        case TYPE::SPEED:
            result = "SPEED";
            break;
        default:
            break;
    }
    return result;
}


