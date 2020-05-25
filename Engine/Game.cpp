//
// Created by Lorenzo Massa on 25/05/2020.
//

#include "Game.h"
#include "../States/MenuState.h"

std::shared_ptr<Game> Game::myGame = nullptr;

Game::Game() {}

std::shared_ptr<Game> Game::getGame() {
    if(myGame == nullptr)
        myGame = std::make_shared<Game>();
    return myGame;
}

const std::shared_ptr<sf::RenderWindow>& Game::getWindow() const {
    return gameWindow;
}

void Game::init() {
    if(gameWindow == nullptr) {
        gameWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), GAME_NAME);
        gameWindow->setFramerateLimit(FPS);
        ptrStateHandler->addState(std::make_shared<MenuState>());
    }
}

void Game::start() {
    while (gameWindow->isOpen()) {
        if(gameClock.getElapsedTime().asSeconds() >= SLEEP_TIME) {
            //timer.check();

            ptrStateHandler->getState()->handleInput();
            ptrStateHandler->getState()->frameCalculator();
            ptrStateHandler->getState()->generateFrame();

            gameWindow->display();

            gameClock.restart();
        }
    }
}

const std::shared_ptr<sf::RenderWindow> &Game::getGameWindow(){
    return gameWindow;
}
