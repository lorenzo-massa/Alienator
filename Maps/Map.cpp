//
// Created by Lorenzo Massa on 30/05/2020.
//

#include <iostream>
#include "Map.h"

Map::Map(int n, int m) : n(n), m(m) {
    mapMatrix.reserve(n*m);
}

void Map::addToMatrix(char& x) {
    mapMatrix.push_back(x);
}

void Map::removeFromMatrix(int i) {
    mapMatrix.erase(mapMatrix.begin()+i);
}

char Map::getFromMatrix(int i) {
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

std::string Map::matrixtoString() {
    std::string string = "";

    for(int i = 0; i < n ; i++)
    {
        for(int j=0; j < m; j++){
            //std::cout<<mapMatrix[i*m+j]<<"  ";
            string.push_back(mapMatrix[i*m+j]);
        }
        string+="\n";
    }

    /*for (auto &a : mapMatrix){
        string+=a;
    }*/

    return string;
}

int Map::getN() const {
    return n;
}

int Map::getM() const {
    return m;
}

void Map::setMatrixValue(int i, char value) {
    mapMatrix[i] = value;
}
