//
// Created by Lorenzo Massa on 12/07/20.
//

#ifndef ALIENATOR_TILE_H
#define ALIENATOR_TILE_H


#include <SFML/Graphics.hpp>
#include "TileEnum.h"

class Tile : public sf::Sprite{
public:

    explicit Tile(sf::Vector2f position, sf::Vector2f size, typeTile type);

    virtual ~Tile();

    typeTile getType() const;

    void setType(typeTile type);

    const sf::Vector2f &getSize() const;

    void setSize(const sf::Vector2f &size);

    bool isBroken1() const;

    void setIsBroken(bool isBroken);

    bool isInvisible();

    bool isBreakable();

    bool isFull();

    bool isMovable();

    bool isBroken2() const;

    int getHp() const;

    void setHp(int hp);

    int shotted();

private:

    typeTile type;

    sf::Vector2f size;

    bool isBroken;

    int hp;
};


#endif //ALIENATOR_TILE_H
