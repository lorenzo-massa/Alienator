//
// Created by th3lo on 27/05/2020.
//

#ifndef ALIENATOR_MAPHANDLER_H
#define ALIENATOR_MAPHANDLER_H


#include "Map.h"
#include "MapFactory.h"
//#include "../Engine/Game.h"
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>



class MapHandler {
public:
    MapHandler();
    //~MapHandler();

    void loadLevel(int i);
    std::shared_ptr<Map> getMap();

private:
    std::shared_ptr<Map> map;
};


#endif //ALIENATOR_MAPHANDLER_H
