//
// Created by Lorenzo Massa on 25/05/2020.
//

#include <iostream>
#include <utility>
#include "MenuState.h"
#include "../Engine/Game.h"
#include "LevelSelectState.h"

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(std::move(targetWindow)),
                                                                       mainMenu(MainMenu(MainMenu::STYLE::MAIN)) {
}

void MenuState::handleInput() {
    sf::Event event;
    while (targetWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                mainMenu.backward();
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                mainMenu.forward();
            if (event.key.code == sf::Keyboard::Enter) {
                switch (mainMenu.getAction()) {
                    case MainMenu::MenuItem::TYPE::START:
                        Game::getGame()->getStateHandler()->addState(std::make_shared<LevelSelectState>(targetWindow));
                        break;
                    case MainMenu::MenuItem::TYPE::EXIT:
                        targetWindow->close();
                        break;
                    default:
                        std::cerr << "Error handling input" << std::endl;
                }
            }
        }
    }
}

void MenuState::generateFrame() {
    targetWindow->clear();
    AssetManager::getAssetManager()->setBackground(targetWindow, 0);


    mainMenu.draw(targetWindow);

}

MenuState::~MenuState() = default;
