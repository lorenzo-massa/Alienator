//
// Created by Lorenzo Massa on 03/07/20.
//

#include <gtest/gtest.h>
#include "../Engine/Game.h"
#include "../States/PlayState.h"
#include "../States/LevelSelectState.h"


class TestEnemyBehavior : public ::testing::Test {
protected:
    std::shared_ptr<Game> game;
    std::shared_ptr<Enemy> enemy;
    std::shared_ptr<Tile> block;


    virtual void SetUp() {
        game = Game::getGame();
        game->init();

        enemy = std::make_shared<Enemy>(EnemyType::Guard,sf::Vector2f(0, 0), 50, 5, sf::Vector2f(8.0f * 64.0f, 0), 7.0f,
                                        sf::Vector2f(128.0f * 2.0f, 32.0f), TypeBehavior::Patrol);

        game->createHero(enemy->getPatrolDistance().x + 5, enemy->getPatrolDistance().y + 5);

    }
};

TEST_F(TestEnemyBehavior, TestOutOfPatrolDistance) {
    sf::Vector2f moveEnemy = sf::Vector2f(0, 0);

    bool found = enemy->patrolling(sf::Vector2f(game->getHero()->getPosition()), moveEnemy, game->getClock()->getElapsedTime().asSeconds());

    ASSERT_EQ(found, false);
}

TEST_F(TestEnemyBehavior, TestInOfPatrolDistance) {
    sf::Vector2f moveEnemy = sf::Vector2f(0, 0);

    game->getHero()->sf::Sprite::move(-6, -6);

    bool found = enemy->patrolling(sf::Vector2f(game->getHero()->getPosition()), moveEnemy, game->getClock()->getElapsedTime().asSeconds());


    ASSERT_EQ(found, true);

}

TEST_F(TestEnemyBehavior, TestInOfPatrolDistanceBehindEnemy) {
    sf::Vector2f moveEnemy = sf::Vector2f(0, 0);

    game->getHero()->sf::Sprite::move(-6, -6);

    enemy->setDirection(sf::Vector2f(-1,0));

    bool found = enemy->patrolling(sf::Vector2f(game->getHero()->getPosition()), moveEnemy, game->getClock()->getElapsedTime().asSeconds());


    ASSERT_EQ(found, false);
}

TEST_F(TestEnemyBehavior, TestPatrolJump) {
    sf::Vector2f moveEnemy = sf::Vector2f(0, 0);

    game->getHero()->sf::Sprite::move(-6, -6);

    bool found = enemy->patrolling(sf::Vector2f(game->getHero()->getPosition()), moveEnemy, game->getClock()->getElapsedTime().asSeconds());


    ASSERT_EQ(found, true);

    enemy->setSpeed(sf::Vector2f(0, 0));

    bool jump = enemy->checkJump();

    ASSERT_EQ(jump, true);

}





