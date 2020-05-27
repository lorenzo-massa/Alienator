//
// Created by leoco on 27/05/2020.
//

#include "Assault.h"

Assault::Assault(int direction, int d, float fR) : Weapon(direction, d, fR) {

}

void Assault::fire() {
    Weapon::fire();
}

