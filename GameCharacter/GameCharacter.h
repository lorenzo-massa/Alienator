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
//#include "../Engine/Game.h"

class GameCharacter{
public:
    GameCharacter(int hp,int ar,int am,int s);

    ~GameCharacter();


    virtual int receiveDamage(int points);

    //virtual bool isLegalMovement(int posX,int direction,int posY);

    virtual void move(int posX, int posY,int speed,int direction);

    virtual void jump(int y);

    virtual void shot(Weapon* weapon);

    int getPosX() const;
    void setPosX(int posX);

    int getPosY() const;
    void setPosY(int posY);

    int getHealthPoint() const;
    void setHealthPoint(int healthPoint);

    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

    int getArmor() const;

    void setArmor(int armor);

    int getSpeed() const;

    void setSpeed(int speed);

    int getAmmo() const;

    void setAmmo(int ammo);

    int getDirection() const;

    void setDirection(int direction);

    void init(sf::Vector2f position, sf::Vector2f size);

    std::shared_ptr<sf::Sprite> getSprite(){
        return sprite;
    }


protected:
    int posX;
    int posY;
    int direction;
    int healthPoint;
    int armor;
    int speed;
    int ammo;
    Weapon * weapon;


    std::shared_ptr<sf::Sprite> sprite;
    std::shared_ptr<sf::Texture> skin;

};

#endif //ALIENATOR_GAMECHARACTER_H