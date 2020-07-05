//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_HERO_H
#define ALIENATOR_HERO_H


#include "GameCharacter.h"

class Hero: virtual public GameCharacter{
public:
    Hero();
    Hero(int type, int hp, int ar, int am, sf::Vector2f s,sf::Vector2f pos,float dir, int coins);

    ~Hero();

    int receiveDamage(int points) override ;

    sf::Vector2f move(sf::Vector2f direction, float delatT) override;

    void jump() override;

    void shot(Weapon* weapon) override;

    int getCoins() const;
    void setCoins(const int coins);

    int getType() const;
    void setType(const int type);



    //PowerUp
    void addCoins(int coins);
    void addAmmo(int ammo);

private:
    int coins;
    int type; //enum? Archer, Boxer, Mage...
};

#endif //ALIENATOR_HERO_H
