//
// Created by th3lo on 27/05/2020.
//

#ifndef ALIENATOR_MAPHANDLER_H
#define ALIENATOR_MAPHANDLER_H

#include <fstream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


#include "Map.h"
#include <AssetsManager.h>

#include "../Objects/Block.h"
#include "../Objects/Collectable.h"


class MapHandler {
public:
    MapHandler();
    ~MapHandler();

    void loadLevel(int i);
    std::shared_ptr<Map> getMap();

private:
    std::shared_ptr<Map> map;

};


#endif //ALIENATOR_MAPHANDLER_H
