//
// Created by Lorenzo Massa on 27/05/2020.
//

#include "MapHandler.h"

MapHandler::MapHandler(){

}

void MapHandler::loadLevel(int i) {
    std::basic_ifstream<char> file = MapFactory::openFile("Maps/Files/level"+std::to_string(i)+".txt");

    int n,m;
    char c;

    file >> n;
    file >> m;

    map = std::make_shared<Map>(n,m);

    for(int i = 0; i < n*m ; i++)
    {
        file.get(c);
        if(c != '\n')
            map->addToMatrix(c);
    }

    std::cout<<map->matrixtoString();


}

std::shared_ptr<Map> MapHandler::getMap() {
    return map;
}
