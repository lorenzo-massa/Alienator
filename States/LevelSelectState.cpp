//
// Created by Lorenzo Massa on 29/05/2020.
//

#include <iostream>
#include "LevelSelectState.h"
#include "../Engine/Game.h"
#include "PlayState.h"

LevelSelectState::LevelSelectState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow), mainMenu(
        MainMenu(MainMenu::STYLE::LEVELS)) {
}

void LevelSelectState::handleInput() {
    sf::Event event;
    while (targetWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                mainMenu.backwardLevel();
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                mainMenu.forwardLevel();
            if (event.key.code == sf::Keyboard::Enter) {
                switch (mainMenu.getAction()) {
                    case MainMenu::MenuItem::TYPE::LEVEL_1:
                        Game::getGame()->getStateHandler()->addState(std::make_shared<PlayState>(targetWindow, 1));
                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_2:
                        if (!Game::getGame()->getLevelCompleted()[0])
                            std::cout << "You have to complete level 1" << std::endl;
                        else
                            Game::getGame()->getStateHandler()->addState(std::make_shared<PlayState>(targetWindow, 2));
                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_3:
                        if (!Game::getGame()->getLevelCompleted()[1])
                            std::cout << "You have to complete level 2" << std::endl;
                        else
                            Game::getGame()->getStateHandler()->addState(std::make_shared<PlayState>(targetWindow, 3));
                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_4:
                        if (!Game::getGame()->getLevelCompleted()[2])
                            std::cout << "You have to complete level 3" << std::endl;
                        else
                            Game::getGame()->getStateHandler()->addState(std::make_shared<PlayState>(targetWindow, 4));
                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_5:
                        if (!Game::getGame()->getLevelCompleted()[3])
                            std::cout << "You have to complete level 4" << std::endl;
                        else
                            Game::getGame()->getStateHandler()->addState(std::make_shared<PlayState>(targetWindow, 5));
                        break;
                    case MainMenu::MenuItem::TYPE::BACK:
                        Game::getGame()->getStateHandler()->removeState();
                        break;
                    default:
                        std::cerr << "Error handling input" << std::endl;
                }
            }
        }
    }
}

void LevelSelectState::generateFrame() {
    targetWindow->clear();
    AssetManager::getAssetManager()->setBackground(targetWindow, 0);

    mainMenu.draw(targetWindow);

}

LevelSelectState::~LevelSelectState() = default;


