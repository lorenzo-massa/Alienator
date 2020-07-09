//
// Created by Lorenzo Massa on 05/06/2020.
//

#include <AssetsManager.h>
#include "Block.h"


Block::Block(sf::Vector2f position) : left(0), right(width), top(0) {
    setTextureRect(sf::IntRect(0, 0, width * 2, height * 2));
    setScale(sf::Vector2f(0.5, 0.5));
    sf::Sprite::setPosition(position);
}

void Block::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
    left = x;
    right = left + width;
    top = y;
}