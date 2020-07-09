//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_BULLET_H
#define ALIENATOR_BULLET_H


#include <SFML/Graphics/Sprite.hpp>

class Bullet : public sf::Sprite {
public:
    Bullet(int dam, float x, float y, sf::Vector2f mousePosition);

    ~Bullet() {}

    void move(float dT);

    void setPosX(int x);

    float getPosX() const;

    void setPosY(int y);

    float getPosY() const;

    int getDamage() const;

    void setDamage(int damage);

    bool isFriendly() const;

    void setFriendly(bool friendly);

    void setPosX1(float posX);

    void setPosY1(float posY);

    const sf::Vector2f &getCurrentSpeed() const;

    void setCurrentSpeed(const sf::Vector2f &currentSpeed);

    float getMaxSpeed() const;

    void setMaxSpeed(float maxSpeed);

private:
    float posX;
    float posY;
    int damage;
    bool friendly;
    sf::Vector2f currentSpeed;
    float maxSpeed;
};

#endif //ALIENATOR_BULLE{}T_H
