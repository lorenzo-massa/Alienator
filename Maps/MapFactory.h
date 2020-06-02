//
// Created by th3lo on 30/05/2020.
//

#ifndef ALIENATOR_MAPFACTORY_H
#define ALIENATOR_MAPFACTORY_H


#include <string>
#include <iostream>
#include <fstream>
#include "../GameCharacter/Enemy.h"

class MapFactory {
public:
    MapFactory();
    ~MapFactory();

    static Enemy* makeEnemy();
    //static Collectable* makeCollectable();

    static std::shared_ptr<std::basic_ifstream<char>>  openFile(std::string filename);
    static void closeFile(std::string filename);

};


#endif //ALIENATOR_MAPFACTORY_H
