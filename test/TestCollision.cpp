//
// Created by Lorenzo Massa on 24/06/2020.
//

#include "gtest/gtest.h"
#include "../Engine/Game.h"
#include "../States/LevelSelectState.h"
#include "../States/PlayState.h"

/*

class TestCollision : public ::testing::Test {
protected:
    std::shared_ptr<Game> game;


    virtual void SetUp() {
        game = Game::getGame();
        game->init();
        game->getStateHandler()->addState(std::make_shared<LevelSelectState>(game->getWindow()));
        game->getMapHandler()->loadLevel(1);
        game->getStateHandler()->addState(std::make_shared<PlayState>(game->getWindow()));

    }



};

TEST_F(TestCollision, collisionTest)
{

}
*/