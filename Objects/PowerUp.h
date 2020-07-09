//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_POWERUP_H
#define ALIENATOR_POWERUP_H

#include <cstdlib>
#include <time.h>
#include <iostream>

class PowerUp {
public:
    enum TYPE {
        COINS = 1,
        MUNITIONS = 2,
        FIRE_RATE = 3,
        SPEED = 4,
        DAMAGE_BOOST = 5,
        INVICIBILITY = 6,
        ERROR
    };

    explicit PowerUp(std::string typeString);

    PowerUp();

    ~PowerUp();

    const std::string getType() const;


private:
    TYPE type;

    TYPE generateRandom();
};


#endif //ALIENATOR_POWERUP_H
