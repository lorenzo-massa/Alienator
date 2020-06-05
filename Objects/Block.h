//
// Created by Lorenzo Massa on 05/06/2020.
//

#ifndef ALIENATOR_BLOCK_H
#define ALIENATOR_BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite {
public:
    Block(sf::Vector2f position);
    float left;
    float right;
    float top;
    float bottom;
    const float height {64};
    const float width {64};
    void setPosition(float x, float y);
};


#endif //ALIENATOR_BLOCK_H
