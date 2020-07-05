//
// Created by Lorenzo Massa on 23/05/2020.
//

#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> targetWindow) : targetWindow(targetWindow) {}

const std::shared_ptr<sf::RenderWindow> &GameState::getTargetWindow() const {
    return targetWindow;
}

void GameState::setTargetWindow(const std::shared_ptr<sf::RenderWindow> &targetWindow) {
    GameState::targetWindow = targetWindow;
}

int GameState::getLevel() const {
    return level;
}

void GameState::setLevel(int level) {
    GameState::level = level;
}
