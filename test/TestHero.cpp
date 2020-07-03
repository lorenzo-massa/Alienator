//
// Created by Lorenzo Massa on 29/06/2020.
//

#include <AssetsManager.h>
#include "gtest/gtest.h"
#include "../GameCharacter/Hero.h"

class TestHero : public ::testing::Test {

protected:


    Hero* hero;

    virtual void SetUp() {
        AssetManager::load();
        auto s = sf::Vector2f(0,0);
        auto pos = sf::Vector2f(0,0);
        hero = new Hero(1,100,50,50,s,pos,0,0);
    }

    virtual void TearDown() {
        delete hero;
    }


};

TEST_F(TestHero,jumpTest){
    auto speed = hero->getSpeed();
    hero->jump();
    ASSERT_EQ(speed.y - 25.0f*64.0f,hero->getSpeed().y);
    ASSERT_EQ(speed.x, hero->getSpeed().x);
}

TEST_F(TestHero,gravityTest){
    float deltaT = 1.0f/60;
    auto direction = sf::Vector2f(0,0);

    auto moving = hero->move(direction, deltaT);

    hero->sf::Sprite::move(moving);

    ASSERT_EQ(0, hero->getPos().x);
    ASSERT_EQ((hero->getSpeed().y*deltaT+0.5f*98.0f*64.0f*deltaT*deltaT)*direction.y, hero->getPos().y);

}
/*
TEST_F(TestHero,shotTest){
    auto bullet = hero->shoot(hero->getRof()/2);
    ASSERT_EQ( bullet, nullptr);
    hero->move(sf::Vector2f(1, 0));
    bullet = hero->shoot(hero->getRof()*2);
    ASSERT_NE(bullet, nullptr);
    ASSERT_GT(bullet->getComponent().x,0);
    hero->move(sf::Vector2f(-1, 0));
    bullet = hero->shoot(hero->getRof()*4);
    ASSERT_NE(bullet, nullptr);
    ASSERT_LT(bullet->getComponent().x,0);
}
 */