//
// Created by th3lo on 27/05/2020.
//

#ifndef ALIENATOR_MAPHANDLER_H
#define ALIENATOR_MAPHANDLER_H


#include "Map.h"
#include "MapFactory.h"
#include <memory>


class MapHandler {
public:
    MapHandler();
    //~MapHandler();

    void loadLevel(int i);
private:
    std::shared_ptr<Map> map;
};


#endif //ALIENATOR_MAPHANDLER_H
