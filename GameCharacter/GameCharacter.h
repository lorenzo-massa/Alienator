//
// Created by Leonardo Corsini on 23/05/2020.
//

#ifndef ALIENATOR_GAMECHARACTER_H
#define ALIENATOR_GAMECHARACTER_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../Weapons/Weapon.h"
#include "../Objects/PowerUp.h"


class GameCharacter : public sf::Sprite {
public:
    GameCharacter();

    GameCharacter(int hp, int ar, int am, sf::Vector2f s, sf::Vector2f pos, sf::Vector2f dir, float speedCoeff);

    virtual ~GameCharacter();

    virtual int receiveDamage(int points);

    virtual sf::Vector2f move( float deltaT);

    virtual void jump();

    virtual std::shared_ptr<Bullet> shot(sf::Vector2f mousePosition);

    sf::Vector2f getPos() const;

    void setPos(sf::Vector2f pos);

    int getHealthPoint() const;

    void setHealthPoint(int healthPoint);

    std::shared_ptr<Weapon> getWeapon() const;

    void setWeapon(std::shared_ptr<Weapon> weapon);

    int getArmor() const;

    void setArmor(int armor);

    sf::Vector2f getSpeed() const;

    void setSpeed(sf::Vector2f speed);

    int getAmmo() const;

    void setAmmo(int ammo);

    sf::Vector2f getDirection() const;

    void setDirection(sf::Vector2f direction);

    float getSpeedBoost() const;

    void setSpeedBoost(float speedBoost);

    bool isInvincibility() const;

    void setInvincibility(bool invincibility);

    const std::string &getStrTexture() const;

    void setStrTexture(const std::string &strTexture);

    const sf::Clock &getClockPowerUp() const;

    void setClockPowerUp(const sf::Clock &clockPowerUp);

    bool isPowerUpState() const;

    void setPowerUpState(bool powerUpState);

    float getFireRateBoost() const;

    void setFireRateBoost(float fireRateBoost);

    float getDamageBoost() const;

    void setDamageBoost(float damageBoost);

    void resetClockPowerUp();

    void removePowerUp();

    const std::shared_ptr<sf::Clock> &getFireRateClock() const;

    void setFireRateClock(const std::shared_ptr<sf::Clock> &fireRateClock);

    const PowerUp getPowerUp() const;

    void setPowerUp(const PowerUp &powerUp);

    float getSpeedCoeff() const;

    void setSpeedCoeff(float speedCoeff);

    const std::shared_ptr<sf::Clock> &getClockAnimation() const;

    void setClockAnimation(const std::shared_ptr<sf::Clock> &clockAnimation);

    bool fireClock(float fireRate);

    bool isLegalJump1() const;

    void setIsLegalJump(bool isLegalJump);

protected:
    sf::Vector2f pos;
    int healthPoint;
    int armor;
    sf::Vector2f speed;
    int ammo;
    std::shared_ptr<Weapon> weapon;
    sf::Vector2f direction;
    std::string strTexture;
    float speedCoeff;


    bool isLegalJump;
    sf::Clock clockPowerUp;
    float speedBoost;
    bool invincibility;
    float fireRateBoost;
    float damageBoost;
    bool powerUpState;
    PowerUp powerUp;

    std::shared_ptr<sf::Clock> clockAnimation;
    std::shared_ptr<sf::Clock> fireRateClock;
};

#endif //ALIENATOR_GAMECHARACTER_H