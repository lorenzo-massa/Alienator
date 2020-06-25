//
// Created by leoco on 27/05/2020.
//

#ifndef ALIENATOR_ENEMYBEHAVIOR_H
#define ALIENATOR_ENEMYBEHAVIOR_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class EnemyBehavior {
public:
    virtual bool patrol(sf::Sprite hero,sf::Sprite enemy ,float deltaT, float directionX);
    virtual void fight();
};
#endif //ALIENATOR_ENEMYBEHAVIOR_H
