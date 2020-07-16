//
// Created by Leonardo Corsini on 24/05/2020.
//

#ifndef ALIENATOR_HERO_H
#define ALIENATOR_HERO_H


#include "GameCharacter.h"

class Hero : virtual public GameCharacter {
public:
    Hero();

    Hero(int type, int hp, int ar, int am, sf::Vector2f s, sf::Vector2f pos, sf::Vector2f dir, float speedCoeff, int coins);

    ~Hero() override;

    int receiveDamage(int points) override;

    sf::Vector2f move( float delatT) override;

    void jump() override;

    std::shared_ptr<Bullet> shot(sf::Vector2f mousePosition) override;

    int getCoins() const;

    void setCoins(const int coins);

    int getType() const;

    void setType(const int type);

    void addCoins(int coins);

    void addAmmo(int ammo);

    void addHealthPoint(int healthPoint);

    bool isWeaponHit() const;

    void setWeaponHit(bool weaponHit);

private:

    bool weaponHit;
    int coins;
    int type; //enum? Archer, Boxer, Mage...
};

#endif //ALIENATOR_HERO_H
