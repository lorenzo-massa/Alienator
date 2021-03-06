//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_POWERUP_H
#define ALIENATOR_POWERUP_H

#include <cstdlib>
#include <ctime>
#include <iostream>

class PowerUp {
public:
    enum class TYPE {
        COINS,
        MUNITIONS,
        FIRE_RATE,
        SPEED,
        DAMAGE_BOOST,
        INVINCIBILITY,
        HEALTH
    };

    explicit PowerUp(TYPE t);

    PowerUp();

    ~PowerUp();

    void setType(TYPE type);

    TYPE getType() const;

    std::string typeToString() const;

private:
    TYPE type;

    static TYPE generateRandom();
};


#endif //ALIENATOR_POWERUP_H
