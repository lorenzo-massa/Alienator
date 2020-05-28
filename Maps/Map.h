//
// Created by Lorenzo Massa on 27/05/2020.
//

#ifndef ALIENATOR_MAP_H
#define ALIENATOR_MAP_H


#include <list>
#include <memory>
#include "../GameCharacter/Enemy.h"

enum class MapType {
    Empty, Block
};

class Map {
public:
    Map();
    ~Map();

private:
    std::list<Enemy> enemies;
    //std::list<Collectable> collectables;
    std::shared_ptr<MapType> matrixMap;
};


#endif //ALIENATOR_MAP_H
