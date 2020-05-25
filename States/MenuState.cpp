//
// Created by th3lo on 25/05/2020.
//

#include <iostream>
#include "MenuState.h"
#include "../Engine/Game.h"

MenuState::MenuState() : GameState(), mainMenu(MainMenu(MainMenu::STYLE::MAIN)) {
}

void MenuState::handleInput() {
    sf::Event event;
    while(targetWindow->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        }
        else if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                mainMenu.backward();
            if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                mainMenu.forward();
            if(event.key.code == sf::Keyboard::Enter) {
                switch (mainMenu.getAction()) {
                    case MainMenu::MenuItem::TYPE::START:
                        //Game::getGameEngine()->getStateHandler().addState(std::make_shared<PlayState>(targetWindow));
                        //Game::getGameEngine()->playGameOst();
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

void MenuState::frameCalculator() {
    float center = Game::getGameWindow()->getView().getCenter().x;
    float offset = Game::getGameWindow()->getView().getSize().x / 2;
}

void MenuState::generateFrame() {
    targetWindow->clear(sf::Color(19, 24, 98));
    mainMenu.draw(targetWindow);

}