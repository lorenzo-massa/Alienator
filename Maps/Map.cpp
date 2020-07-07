//
// Created by Lorenzo Massa on 30/05/2020.
//

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

void Map::addEnemy(std::shared_ptr<Enemy> e) {
    enemies.push_back(e);
}

void Map::removeEnemy(int i) {
    enemies.erase(enemies.begin()+i);
}

std::shared_ptr<Enemy> Map::getEnemy(int i) {
    return enemies[i];
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

std::vector<std::shared_ptr<Enemy>> Map::getEnemies() {
    return enemies;
}

void Map::addCollectable(std::shared_ptr<Collectable> c) {
    collectables.push_back(c);
}

void Map::removeCollectable(int i) {
    collectables.erase(collectables.begin()+i);
}

std::shared_ptr<Collectable> Map::getCollectable(int i) {
    return collectables[i];
}

std::vector<std::shared_ptr<Collectable>> Map::getCollectables() {
    return collectables;
}

void Map::addBullet(std::shared_ptr<Bullet> b) {
    bullets.push_back(b);
}

void Map::removeBullet(int i) {
    bullets.erase(bullets.begin()+i);
}

std::shared_ptr<Bullet> Map::getBullet(int i) {
    return bullets[i];
}

std::vector<std::shared_ptr<Bullet>> Map::getBullets() {
    return bullets;
}

const std::shared_ptr<sf::Sprite> &Map::getPortal() const {
    return portal;
}

void Map::setPortal(const std::shared_ptr<sf::Sprite> &portal) {
    Map::portal = portal;
}
