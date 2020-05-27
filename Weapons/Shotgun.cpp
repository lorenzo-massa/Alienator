//
// Created by leoco on 27/05/2020.
//

#include "Shotgun.h"

Shotgun::Shotgun(int direction, int d, float fR) : Weapon(direction, d, fR) {

}

void Shotgun::fire() {
    Weapon::fire();
}

