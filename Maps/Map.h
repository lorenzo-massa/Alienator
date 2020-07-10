//
// Created by Lorenzo Massa on 30/05/2020.
//

#ifndef ALIENATOR_MAP_H
#define ALIENATOR_MAP_H


#include <list>
#include <memory>
#include <vector>

#include "../GameCharacter/Enemy.h"
#include "../Objects/Collectable.h"

class Map {
public:
    Map();

    ~Map();

    void addToMatrix(const std::shared_ptr<sf::Sprite>& x);

    void removeFromMatrix(int i);

    std::shared_ptr<sf::Sprite> getFromMatrix(int i);

    std::vector<std::shared_ptr<sf::Sprite>> getMatrix();

    void addEnemy(const std::shared_ptr<Enemy>& e);

    void removeEnemy(int t);

    std::shared_ptr<Enemy> getEnemy(int i);

    std::vector<std::shared_ptr<Enemy>> getEnemies();

    void addCollectable(const std::shared_ptr<Collectable>& c);

    void removeCollectable(int i);

    std::shared_ptr<Collectable> getCollectable(int i);

    std::vector<std::shared_ptr<Collectable>> getCollectables();

    void addBullet(const std::shared_ptr<Bullet>& b);

    void removeBullet(int i);

    std::shared_ptr<Bullet> getBullet(int i);

    std::vector<std::shared_ptr<Bullet>> getBullets();

    const std::shared_ptr<sf::Sprite> &getPortal() const;

    void setPortal(const std::shared_ptr<sf::Sprite> &portal);

    int getN() const;

    void setN(int n);

    int getM() const;

    void setM(int m);


    void loadLevel(int i);

    void reset();


private:
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Collectable>> collectables;
    std::vector<std::shared_ptr<sf::Sprite>> mapMatrix;
    std::vector<std::shared_ptr<Bullet>> bullets;
    std::shared_ptr<sf::Sprite> portal;
    int n{};
    int m{};
};


#endif //ALIENATOR_MAP_H
