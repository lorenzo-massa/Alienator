//
// Created by Leonardo Corsini on 23/05/2020.
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
    GameCharacter();
    GameCharacter(int hp,int ar,int am,sf::Vector2f s,sf::Vector2f pos,float dir);

    virtual ~GameCharacter();

    virtual int receiveDamage(int points);

    virtual sf::Vector2f move(sf::Vector2f direction,float deltaT);

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

    float getSpeedBoost() const;

    void setSpeedBoost(float speedBoost);

    bool isInvincibility() const;

    void setInvincibility(bool invincibility);

    const std::string &getStrTexture() const;

    void setStrTexture(const std::string &strTexture);

protected:
    sf::Vector2f pos;
    int healthPoint;
    int armor;
    sf::Vector2f speed;
    int ammo;
    Weapon * weapon;
    float direction;
    std::string strTexture;

    float speedBoost;
    bool invincibility;

};

#endif //ALIENATOR_GAMECHARACTER_H