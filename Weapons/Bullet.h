//
// Created by leoco on 24/05/2020.
//

#ifndef ALIENATOR_BULLET_H
#define ALIENATOR_BULLET_H




class Bullet{
public:
    Bullet(int dam,int d,int x,int y);//TODO direction? posX,posY di weapon?
    ~Bullet(){}

    void move(float dir,float coeffAng,float dT);

    void setPosX(int x);
    int getPosX() const;

    void setPosY(int y);
    int getPosY() const;

    void setDirection(int d);
    int getDirection()const;

    int getDamage() const;
    void setDamage(int damage);

private:
    int posX;
    int posY;
    int damage;
    int direction;
};

#endif //ALIENATOR_BULLE{}T_H
