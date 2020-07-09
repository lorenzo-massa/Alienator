//
// Created by Lorenzo Massa on 05/06/2020.
//

#ifndef ALIENATOR_BLOCK_H
#define ALIENATOR_BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite {
public:
    Block(sf::Vector2f position);


    void setPosition(float x, float y);

private:
    const float height{64};
    const float width{64};

    float left;
    float right;
    float top;
    float bottom;
};


#endif //ALIENATOR_BLOCK_H
