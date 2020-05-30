//
// Created by Lorenzo Massa on 30/05/2020.
//

#ifndef ALIENATOR_MAP_H
#define ALIENATOR_MAP_H


#include <list>
#include <memory>
#include <vector>

#include "../GameCharacter/Enemy.h"

class Map {
public:
    explicit Map(int n, int m);
    //~Map();

    void addToMatrix(char& x);
    void removeFromMatrix(int i);
    char getFromMatrix(int i);

    void addEnemy(Enemy& e);
    void removeEnemy(int t);
    Enemy getEnemy(int i);

    std::string matrixtoString();



private:
    std::vector<Enemy> enemies;
    //std::list<Collectable> collectables;
    std::vector<char> mapMatrix;
    int n;
    int m;
};


#endif //ALIENATOR_MAP_H
