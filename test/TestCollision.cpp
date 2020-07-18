//
// Created by Lorenzo Massa on 24/06/2020.
//

#include "gtest/gtest.h"
#include "../Engine/Game.h"
#include "../States/LevelSelectState.h"
#include "../States/PlayState.h"
#include <memory>


class TestCollision : public ::testing::Test {
protected:
    std::shared_ptr<Game> game;
    std::shared_ptr<PlayState> playState;
    std::shared_ptr<sf::Sprite> e1;
    std::shared_ptr<sf::Sprite> e2;
    const float eps = 0.0001;

protected:

    virtual void SetUp() {
        game = Game::getGame();
        game->init();
        game->getStateHandler()->addState(std::make_shared<LevelSelectState>(game->getWindow()));
        game->getMap()->loadLevel(1);
        playState = std::make_shared<PlayState>(game->getWindow(), 1);
        game->getStateHandler()->addState(playState);

        game->createHero(0, 0);

        e1 = std::make_shared<GameCharacter>(100, 100, 100, sf::Vector2f(0, 0), sf::Vector2f(5, 5), sf::Vector2f(0, 0), 1);
        e1->setTexture(AssetManager::getAssetManager()->getTextures().at("PORTAL"));
        e1->setScale(0.15f, 0.17f);
        e2 = std::make_shared<GameCharacter>(100, 100, 100, sf::Vector2f(0, 0), sf::Vector2f(5, 6), sf::Vector2f(0, 0), 1);
        e2->setTexture(AssetManager::getAssetManager()->getTextures().at("PORTAL"));
        e2->setScale(0.15f, 0.17f);
        e2->setColor(sf::Color::Red);

    }

};

TEST_F(TestCollision, collisionSprite) {
    playState->generateFrame();
    game->getWindow()->draw(*e1);
    game->getWindow()->draw(*e2);

    ASSERT_EQ(playState->checkCollision(e1, e2), true);

    e2->move(sf::Vector2f(100, 10));

    ASSERT_EQ(playState->checkCollision(e1, e2), false);

}

TEST_F(TestCollision, isLegalMovementY) {
    e1->setPosition(0, game->getHero()->getTexture()->getSize().y * game->getHero()->getScale().y + 10);
    sf::Vector2f moving = sf::Vector2f(0, 10.5f);

    playState->detectCollision(game->getHero(), e1, moving);

    ASSERT_LT(moving.y - 10.0f, eps);
}

TEST_F(TestCollision, isLegalMovementX) {
    e1->setPosition(game->getHero()->getTexture()->getSize().x * game->getHero()->getScale().x + 10, 0);
    sf::Vector2f moving = sf::Vector2f(10.5f, 0);

    playState->detectCollision(game->getHero(), e1, moving);

    ASSERT_LT(moving.x - 10.0f, eps);
}
