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

    void addToMatrix(std::shared_ptr<sf::Sprite> x);
    void removeFromMatrix(int i);
    std::shared_ptr<sf::Sprite> getFromMatrix(int i);
    std::vector<std::shared_ptr<sf::Sprite>> getMatrix();

    void addEnemy(Enemy& e);
    void removeEnemy(int t);
    Enemy getEnemy(int i);

    int getN() const;
    int getM() const;


private:
    std::vector<Enemy> enemies;
    //std::list<Collectable> collectables;
    std::vector<std::shared_ptr<sf::Sprite>> mapMatrix;
    int n;
    int m;
};


#endif //ALIENATOR_MAP_H
