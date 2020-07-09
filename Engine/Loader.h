//
// Created by Lorenzo Massa on 10/06/2020.
//

#ifndef ALIENATOR_LOADER_H
#define ALIENATOR_LOADER_H

#include <iostream>
#include <fstream>
#include <memory>
#include "../GameCharacter/Hero.h"

class Loader {
public:
    static void saveHero(int coins, int ammo, int armor);

    static void loadHero();
};


#endif //ALIENATOR_LOADER_H
