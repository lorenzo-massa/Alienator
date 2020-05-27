//
// Created by leoco on 27/05/2020.
//

#include "Sniper.h"

Sniper::Sniper(int direction, int d, float fR) : Weapon(direction, d, fR) {

}

void Sniper::fire() {
    Weapon::fire();
}



