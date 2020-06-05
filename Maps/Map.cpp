//
// Created by Lorenzo Massa on 30/05/2020.
//

#include <iostream>
#include "Map.h"

Map::Map(int n, int m) : n(n), m(m) {
    mapMatrix.reserve(n*m);
}

void Map::addToMatrix(std::shared_ptr<sf::Sprite> x) {
    mapMatrix.push_back(x);
}

void Map::removeFromMatrix(int i) {
    mapMatrix.erase(mapMatrix.begin()+i);
}

std::shared_ptr<sf::Sprite> Map::getFromMatrix(int i) {
    return mapMatrix[i];
}

void Map::addEnemy(Enemy &e) {
    enemies.push_back(e);
}

void Map::removeEnemy(int i) {
    enemies.erase(enemies.begin()+i);
}

Enemy Map::getEnemy(int i) {
    return enemies.at(i);
}

int Map::getN() const {
    return n;
}

int Map::getM() const {
    return m;
}

std::vector<std::shared_ptr<sf::Sprite>> Map::getMatrix() {
    return mapMatrix;
}
