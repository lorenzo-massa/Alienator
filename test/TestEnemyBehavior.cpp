//
// Created by Lorenzo Massa on 03/07/20.
//

#include <gtest/gtest.h>

/*
class TestEnemyBehavior : public ::testing::Test {
protected:
    virtual void SetUp() {
        AssetManager::load();
        AssetManager::setFrames();
        TargetWindow targetWindow = std::make_shared<sf::RenderWindow>();
        PlayState state = PlayState(targetWindow);
    }

    virtual void TearDown() {

    }
};

TEST_F(TestEnemyBehavior, TEST_BRAWLER_ACTION) {
//(0, 0)
auto brawler = GameFactory::makeBrawlewr(0);
auto action = brawler->action(sf::Vector2f(1000, 1000));
ASSERT_GT(brawler->getSpeed().x, 0);
ASSERT_GT(brawler->getSpeed().y, 0);
ASSERT_EQ(action, nullptr);

}

TEST_F(TestEnemyBehavior, TEST_WATCHER_ACTION) {
auto watcher = GameFactory::makeWatcher(0);
auto color = watcher->getColor().a;
auto bullet = watcher->action(sf::Vector2f(3000,0));
for(int i=0; i<300; i++){
watcher->action(sf::Vector2f(3000,0));
ASSERT_LE(watcher->getColor().a, color);
color = watcher->getColor().a;
}
EXPECT_EQ(color,30);
for (int i=0; i<300; i++){
watcher->action(sf::Vector2f(0,0));
ASSERT_GE(watcher->getColor().a, color);
color = watcher->getColor().a;
}
EXPECT_EQ(color, 255);
ASSERT_EQ(bullet, nullptr);
}

TEST_F(TestEnemyBehavior, TEST_ARCHER_ACTION){
Timer::getTimer();
auto archer = GameFactory::makeArcher(0);
sf::Clock clock;
clock.restart();
while (clock.getElapsedTime() < sf::seconds(4)){}
auto bullet = archer->action(sf::Vector2f(2,0));
ASSERT_NE(bullet, nullptr);
ASSERT_GT(bullet->getComponent().x,0);
clock.restart();
while (clock.getElapsedTime() < sf::seconds(4)){}
bullet = archer->action(sf::Vector2f(-1,0));
ASSERT_NE(bullet, nullptr);
ASSERT_LT(bullet->getComponent().x,0);
bullet = archer->action(sf::Vector2f(-1,0));
ASSERT_EQ(bullet, nullptr);

}

 */