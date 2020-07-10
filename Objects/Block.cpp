//
// Created by Lorenzo Massa on 05/06/2020.
//

#include "Block.h"


Block::Block(sf::Vector2f position) {
    setTextureRect(sf::IntRect(0, 0, width * 2, height * 2));
    setScale(sf::Vector2f(0.5, 0.5));
    sf::Sprite::setPosition(position);
}
