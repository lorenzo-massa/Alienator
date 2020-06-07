//
// Created by leoco on 23/05/2020.
//

#ifndef ALIENATOR_GAMECHARACTER_H
#define ALIENATOR_GAMECHARACTER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Weapons/Weapon.h"


class GameCharacter : public sf::Sprite{
public:
    GameCharacter(int hp,int ar,int am,sf::Vector2f s,sf::Vector2f pos,float dir);

    ~GameCharacter();

    virtual int receiveDamage(int points);

    //virtual bool isLegalMovement(char comparison);

    virtual void move(sf::Vector2f direction,float deltaT);

    virtual void jump();

    virtual void shot(Weapon* weapon);

    sf::Vector2f getPos() const;
    void setPos(sf::Vector2f pos);

    int getHealthPoint() const;
    void setHealthPoint(int healthPoint);

    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

    int getArmor() const;

    void setArmor(int armor);

    sf::Vector2f getSpeed() const;

    void setSpeed(sf::Vector2f speed);

    int getAmmo() const;

    void setAmmo(int ammo);

    float getDirection() const;

    void setDirection(float direction);

protected:
    sf::Vector2f pos;
    int healthPoint;
    int armor;
    sf::Vector2f speed;
    int ammo;
    Weapon * weapon;
    float direction;

    void init(sf::Vector2f position, sf::Vector2f size);
};

#endif //ALIENATOR_GAMECHARACTER_H