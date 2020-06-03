//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_COLLECTABLE_H
#define ALIENATOR_COLLECTABLE_H


#include <memory>
#include <SFML/Graphics.hpp>
#include "PowerUp.h"

class Collectable {
public:
    Collectable();
    explicit Collectable(std::string type);
    ~Collectable();

    const std::shared_ptr<sf::Sprite> &getSprite() const;

    void setSprite(const std::shared_ptr<sf::Sprite> &sprite);

    const std::shared_ptr<sf::Texture> &getSkin() const;

    void setSkin(const std::shared_ptr<sf::Texture> &skin);

    const PowerUp &getPowerUp() const;

    void setPowerUp(const PowerUp &powerUp);

private:
    std::shared_ptr<sf::Sprite> sprite;
    std::shared_ptr<sf::Texture> skin;
    PowerUp powerUp;
};


#endif //ALIENATOR_COLLECTABLE_H
