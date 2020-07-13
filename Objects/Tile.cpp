//
// Created by Lorenzo Massa on 12/07/20.
//

#include "Tile.h"


Tile::Tile(sf::Vector2f position, sf::Vector2f size, typeTile type): size(size), type(type), isBroken(false), hp(3) {
    setTextureRect(sf::IntRect(0, 0, size.x * 2, size.y * 2));
    setScale(sf::Vector2f(0.5, 0.5));
    sf::Sprite::setPosition(position);
}

bool Tile::isFull() {
    return type == typeTile::Full;
}

bool Tile::isBreakable() {
    return type == typeTile::Breakable;
}

bool Tile::isInvisible() {
    return type == typeTile::Invisible;
}

bool Tile::isMovable() {
    return type == typeTile::Movable;

}

typeTile Tile::getType() const {
    return type;
}

void Tile::setType(typeTile type) {
    Tile::type = type;
}

const sf::Vector2f &Tile::getSize() const {
    return size;
}

void Tile::setSize(const sf::Vector2f &size) {
    Tile::size = size;
}

bool Tile::isBroken1() const {
    return isBroken;
}

void Tile::setIsBroken(bool isBroken) {
    Tile::isBroken = isBroken;
}

bool Tile::isBroken2() const {
    return isBroken;
}

int Tile::getHp() const {
    return hp;
}

void Tile::setHp(int hp) {
    Tile::hp = hp;
}

Tile::~Tile() {
}

int Tile::shotted() {
    hp -= 1;

    return hp;
}


