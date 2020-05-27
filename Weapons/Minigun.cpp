//
// Created by leoco on 27/05/2020.
//

#include "Minigun.h"

Minigun::Minigun(int direction, int d, float fR) : Weapon(direction, d, fR) {

}

void Minigun::fire() {
    Weapon::fire();
}

