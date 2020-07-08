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


protected:

    virtual void SetUp() {
        game = Game::getGame();
        game->init();
        game->getStateHandler()->addState(std::make_shared<LevelSelectState>(game->getWindow()));
        game->getMapHandler()->loadLevel(1);
        playState = std::make_shared<PlayState>(game->getWindow(),1);
        game->getStateHandler()->addState(playState);

        e1 = std::make_shared<GameCharacter>(100,100,100,sf::Vector2f (0,0),sf::Vector2f(5,5),0);
        e1->setTexture(AssetManager::textures.at("PORTAL"));
        e1->setScale(0.15f,0.17f);
        e2 = std::make_shared<GameCharacter>(100,100,100,sf::Vector2f (0,0),sf::Vector2f(5,6),0);
        e2->setTexture(AssetManager::textures.at("PORTAL"));
        e2->setScale(0.15f,0.17f);
        e2->setColor(sf::Color::Red);

    }

};

TEST_F(TestCollision, collisionSprite)
{

    playState->generateFrame();
    game->getWindow()->draw(*e1);
    game->getWindow()->draw(*e2);

    ASSERT_EQ(playState->checkCollision(e1,e2),true);

    e2->move(sf::Vector2f(100,10));

    ASSERT_EQ(playState->checkCollision(e1,e2),false);

}
