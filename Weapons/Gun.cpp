//
// Created by leoco on 27/05/2020.
//

#include "Gun.h"

Gun::Gun(int direction, int d, float fR) : Weapon(direction, d, fR) {

}

void Gun::fire() {
    Weapon::fire();
}

