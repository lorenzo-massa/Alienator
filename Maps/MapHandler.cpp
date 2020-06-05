//
// Created by Lorenzo Massa on 27/05/2020.
//

#include <SFML/Graphics.hpp>
#include <AssetsManager.h>
#include "MapHandler.h"
#include "../Engine/Game.h"
#include "../Objects/Block.h"

MapHandler::MapHandler(){

}

void MapHandler::loadLevel(int x) {
    std::shared_ptr<std::basic_ifstream<char>> file = MapFactory::openFile("Maps/Files/level"+std::to_string(x)+".txt");

    int n,m;
    char c;

    *file >> n;
    *file >> m;

    map = std::make_shared<Map>(n,m);

    int i=0;
    int j=0;

    while(i < n)
    {
        j=0;
        while(j < m) {

            file->get(c);

            if (c != '\n') {

                std::shared_ptr<Block> b;
                switch (c) {
                    case 'B':
                        b = std::make_shared<Block>(sf::Vector2f(j * 64, i * 64));
                        b->setTexture(AssetManager::textures.at("2"));
                        map->addToMatrix(b);
                        break;
                    case 'P':
                        Game::getGame()->createHero(i*64,j*64);
                        break;
                    default:
                        break;
                }
                j++;
            }
        }
        i++;
    }


}

std::shared_ptr<Map> MapHandler::getMap() {
    return map;
}
