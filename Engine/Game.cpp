//
// Created by Lorenzo Massa on 25/05/2020.
//

#include "Game.h"
#include "../States/PlayState.h"


std::shared_ptr<Game> Game::myGame = nullptr;

Game::Game() {
    ptrStateHandler = std::make_shared<StateHandler>();
    gameWindow = nullptr;
    ptrMap = std::make_shared<Map>();
    clock = std::make_shared<sf::Clock>();

    for (int i = 0; i < 5; i++)
        levelCompleted.push_back(false);
}

Game::~Game() = default;

std::shared_ptr<Game> Game::getGame() {
    if (Game::myGame == nullptr)
        myGame = std::make_shared<Game>();
    return myGame;
}

const std::shared_ptr<sf::RenderWindow> &Game::getWindow() const {
    return gameWindow;
}

void Game::init() {

    if (gameWindow == nullptr) {
        //gameWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), GAME_NAME, sf::Style::Fullscreen);
        gameWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), GAME_NAME);
        gameWindow->setVerticalSyncEnabled(true);
        gameWindow->setFramerateLimit(FPS);
        std::cout << "All textures are loaded!" << std::endl;

        ptrStateHandler->addState(std::make_shared<MenuState>(gameWindow));
        AssetManager::load();
        std::cout << "All textures are loaded!" << std::endl;

        srand(time(nullptr));


    }
}

void Game::start() {
    while (gameWindow->isOpen()) {
        if (clock->getElapsedTime().asSeconds() >= SLEEP_TIME) {

            ptrStateHandler->getState()->handleInput();

            ptrStateHandler->getState()->generateFrame();

            gameWindow->display();

            clock->restart();
        }
    }
}

std::shared_ptr<StateHandler> Game::getStateHandler() {
    return Game::ptrStateHandler;
}

std::shared_ptr<Map> Game::getMap() {
    return Game::ptrMap;
}


void Game::createHero(int x, int y) {
    ptrHero = std::make_shared<Hero>(1, 100, 10, 50, sf::Vector2f(0, 0), sf::Vector2f(x, y), 0, 10.0f, 0);
    Loader::loadHero();
}

void Game::setPtrHero(std::shared_ptr<Hero> ptr) {
    ptrHero = ptr;
}

std::shared_ptr<Hero> Game::getHero() {
    return Game::ptrHero;
}

std::shared_ptr<sf::Clock> Game::getClock() {
    return clock;
}

void Game::save() {
    Loader::saveHero(ptrHero->getCoins(), ptrHero->getAmmo(), ptrHero->getArmor());
}

void Game::addSubject(std::shared_ptr<SubjectGame> subject) {
    subjects.push_back(subject);
}

void Game::removeSubject(std::shared_ptr<SubjectGame> subject) {
    subjects.remove(subject);
}

void Game::removeSubject(int i) {
    std::_List_iterator<std::shared_ptr<SubjectGame>> it = subjects.begin();
    std::advance(it, i);
    subjects.erase(it);
}

std::shared_ptr<SubjectGame> Game::getSubject(int i) {
    std::_List_iterator<std::shared_ptr<SubjectGame>> it = subjects.begin();
    std::advance(it, i);
    return *it;
}

void Game::update(int i) {

    std::shared_ptr<Collectable> c = getMap()->getCollectable(i);

    std::string typeString = c->getPowerUp().getType();

    if (typeString == "COINS")
        ptrHero->addCoins(10);
    else if (typeString == "MUNITIONS")
        ptrHero->addAmmo(25);
    else if (typeString == "FIRE_RATE") {
        ptrHero->removePowerUp();
        ptrHero->setFireRateBoost(1.5f);//TODO implementare rateo di fuoco con un clock
        ptrHero->setPowerUpState(true);
        ptrHero->setTypePowerUp("FIRE_RATE");
        ptrHero->resetClockPowerUp();
    } else if (typeString == "SPEED") {
        ptrHero->removePowerUp();
        ptrHero->setSpeedBoost(1.5f);
        ptrHero->setPowerUpState(true);
        ptrHero->setTypePowerUp("SPEED");
        ptrHero->resetClockPowerUp();
    } else if (typeString == "DAMAGE_BOOST") {
        ptrHero->removePowerUp();
        ptrHero->setDamageBoost(1.5f);
        ptrHero->setPowerUpState(true);
        ptrHero->setTypePowerUp("DAMAGE_BOOST");
        ptrHero->resetClockPowerUp();
    } else if (typeString == "INVICIBILITY") {
        ptrHero->removePowerUp();
        ptrHero->setInvincibility(true);
        ptrHero->setPowerUpState(true);
        ptrHero->setTypePowerUp("INVINCIBILITY");
        ptrHero->resetClockPowerUp();
    } else
        std::cerr << "Error loading power up: undefined string: " << typeString << std::endl;

    getMap()->removeCollectable(i);
    removeSubject(i);

}

void Game::killHero() {

    ptrHero->~Hero();

    int level = ptrStateHandler->getState()->getLevel();

    ptrStateHandler->removeState();

    ptrMap->reset();

    if (level > 0 && level < 6)
        ptrStateHandler->addState(std::make_shared<PlayState>(gameWindow, level));
    else
        std::cerr << "Error loading level" << std::endl;

    std::cout<<"KILLED"<<std::endl;

}

const std::vector<bool> &Game::getLevelCompleted() const {
    return levelCompleted;
}

void Game::setLevelCompleted(const std::vector<bool> &levelCompleted) {
    Game::levelCompleted = levelCompleted;
}

void Game::finishLevel(int i) {
    levelCompleted[i - 1] = true;
    ptrStateHandler->removeState();
}


