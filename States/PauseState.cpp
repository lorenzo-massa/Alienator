//
// Created by Lorenzo Massa on 02/06/2020.
//

#include <iostream>
#include "PauseState.h"
#include "../Engine/Game.h"


PauseState::PauseState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow),
                                                                         mainMenu(MainMenu(MainMenu::STYLE::PAUSE)) {
}

void PauseState::handleInput() {
    sf::Event event;
    while (targetWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                Game::getGame()->getStateHandler()->removeState();
            }
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                mainMenu.backward();
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                mainMenu.forward();
            if (event.key.code == sf::Keyboard::Enter) {
                switch (mainMenu.getAction()) {
                    case MainMenu::MenuItem::TYPE::RESUME:
                        Game::getGame()->getStateHandler()->removeState();
                        break;
                    case MainMenu::MenuItem::TYPE::QUIT:
                        Game::getGame()->getStateHandler()->removeState();
                        Game::getGame()->getStateHandler()->removeState();
                        Game::getGame()->getStateHandler()->removeState();
                        break;
                    default:
                        std::cerr << "Error handling input" << std::endl;
                }
            }
        }
    }
}

void PauseState::generateFrame() {
    targetWindow->clear();
    AssetManager::getAssetManager()->setBackground(targetWindow, 0);

    mainMenu.draw(targetWindow);
}


