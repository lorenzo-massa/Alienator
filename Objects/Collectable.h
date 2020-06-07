//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_COLLECTABLE_H
#define ALIENATOR_COLLECTABLE_H


#include <memory>
#include <SFML/Graphics.hpp>
#include "PowerUp.h"

class Collectable : public sf::Sprite {
public:
    explicit Collectable(sf::Vector2f position);
    Collectable(sf::Vector2f position, std::string type);
    ~Collectable();


    const PowerUp &getPowerUp() const;

    void setPowerUp(const PowerUp &powerUp);

private:
    const float height {512};
    const float width {512};

    PowerUp powerUp;
};


#endif //ALIENATOR_COLLECTABLE_H
