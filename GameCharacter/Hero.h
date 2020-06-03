//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_HERO_H
#define ALIENATOR_HERO_H


#include "GameCharacter.h"

class Hero: virtual public GameCharacter{
public:
    Hero(int hp, int ar, int am, int s=1);
    ~Hero();

    int receiveDamage(int points) override ;

    bool isLegalMovement(char comparison) override;

    void move(sf::Vector2f direction) override;

    void jump(int y) override;

    void shot(Weapon* weapon) override;

    int getCoins() const;
    void setCoins(int coins);

private:
    int coins;

};

#endif //ALIENATOR_HERO_H
