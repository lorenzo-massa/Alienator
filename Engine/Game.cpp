//
// Created by Lorenzo Massa on 25/05/2020.
//

#include "Game.h"

std::shared_ptr<Game> Game::myGame = nullptr;

Game::Game(){
    ptrStateHandler = std::make_shared<StateHandler>();
    gameWindow = nullptr;
    ptrMapHandler = std::make_shared<MapHandler>();
    clock = std::make_shared<sf::Clock>();
}
Game::~Game() = default;

std::shared_ptr<Game> Game::getGame() {
    if(Game::myGame == nullptr)
        myGame = std::make_shared<Game>();
    return myGame;
}

const std::shared_ptr<sf::RenderWindow>& Game::getWindow() const {
    return gameWindow;
}

void Game::init() {
    if(gameWindow == nullptr) {
        gameWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), GAME_NAME);
        //gameWindow->setFramerateLimit(FPS);
        gameWindow->setVerticalSyncEnabled(true);
        gameWindow->setFramerateLimit(FPS);
        ptrStateHandler->addState(std::make_shared<MenuState>(gameWindow));
        AssetManager::load();
        AssetManager::setFrames();
    }
}

void Game::start() {
    while (gameWindow->isOpen()) {
        if(clock->getElapsedTime().asSeconds() >= SLEEP_TIME) {
            //timer.check();

            ptrStateHandler->getState()->handleInput();

            ptrStateHandler->getState()->frameCalculator();

            ptrStateHandler->getState()->generateFrame();

            gameWindow->display();

            clock->restart();
        }
    }
}

std::shared_ptr<StateHandler> Game::getStateHandler() {
    return Game::ptrStateHandler;
}

std::shared_ptr<MapHandler> Game::getMapHandler() {
    return Game::ptrMapHandler;
}

void Game::setMyGame(const std::shared_ptr<Game> &myGame) {
    Game::myGame = myGame;
}

void Game::createHero(int x/*int y*/) {
    ptrHero = std::make_shared<Hero>(10,10,10,10);
    //ptrHero->setPos(x);
   // ptrHero->setPosY(y);
}

std::shared_ptr<Hero> Game::getHero() {
    return Game::ptrHero;
}

std::shared_ptr<sf::Clock> Game::getClock() {
    return clock;
}


