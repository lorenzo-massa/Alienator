//
// Created by Lorenzo Massa on 25/05/2020.
//

#include "Game.h"
#include "../States/MenuState.h"


const std::shared_ptr<sf::RenderWindow>& Game::getWindow() const {
    return gameWindow;
}

void Game::init() {
    if(gameWindow == nullptr) {
        gameWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), GAME_NAME);
        gameWindow->setFramerateLimit(FPS);
        std::shared_ptr<MenuState> newState = std::make_shared<MenuState>(gameWindow);
        ptrStateHandler->addState(newState);
    }
}

void Game::start() {
    while (gameWindow->isOpen()) {
        if(gameClock.getElapsedTime().asSeconds() >= SLEEP_TIME) {
            timer.check();

            ptrStateHandler->getState()->handleInput();
            ptrStateHandler->getState()->frameCalculator();
            ptrStateHandler->getState()->generateFrame();

            gameWindow->display();

            gameClock.restart();
        }
    }
}

const std::shared_ptr<sf::RenderWindow> &Game::getGameWindow() const {
    return gameWindow;
}
