//
// Created by Lorenzo Massa on 29/06/2020.
//

#include <AssetsManager.h>
#include "gtest/gtest.h"
#include "../GameCharacter/Hero.h"

class TestHero : public ::testing::Test {

protected:


    Hero *hero;

    virtual void SetUp() {
        AssetManager::load();
        auto s = sf::Vector2f(0, 0);
        auto pos = sf::Vector2f(0, 0);
        hero = new Hero(1, 100, 50, 50, s, pos, 0, 1, 0);
    }

    virtual void TearDown() {
        delete hero;
    }


};

TEST_F(TestHero, jumpTest) {
    auto speed = hero->getSpeed();
    hero->jump();

    ASSERT_EQ(speed.y - 25.0f * 64.0f, hero->getSpeed().y);
    ASSERT_EQ(speed.x, hero->getSpeed().x);
}

TEST_F(TestHero, gravityTest) {
    float deltaT = 1.0f / 60;
    auto direction = sf::Vector2f(0, 0);
    auto moving = hero->move(direction, deltaT);

    hero->sf::Sprite::move(moving);

    ASSERT_EQ(0, hero->getPosition().x);
    ASSERT_EQ((hero->getSpeed().y * deltaT + 0.5f * 98.0f * 64.0f * deltaT * deltaT) * direction.y,
              hero->getPosition().y);

}

TEST_F(TestHero, shotTest) {
    auto bullet = hero->shot(sf::Vector2f(hero->getPos().x + 50,
                                          hero->getPos().y + hero->getTexture()->getSize().y * hero->getScale().y));

    ASSERT_NE(bullet, nullptr);

    ASSERT_EQ(bullet->getPosition().x, hero->getPosition().x + 32);
    ASSERT_EQ(bullet->getPosition().y, hero->getPosition().y + 64);
}



