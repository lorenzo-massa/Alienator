//
// Created by Lorenzo Massa on 29/05/2020.
//

#include <iostream>
#include "LevelSelectState.h"
#include "../Engine/Game.h"
#include "../Maps/MapFactory.h"
#include "PlayState.h"

LevelSelectState::LevelSelectState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow), mainMenu(MainMenu(MainMenu::STYLE::LEVELS)) {
}

void LevelSelectState::handleInput() {
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
                    case MainMenu::MenuItem::TYPE::LEVEL_1:
                        Game::getGame()->getMapHandler()->loadLevel(1);
                        Game::getGame()->getStateHandler()->addState(std::make_shared<PlayState>(targetWindow));
                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_2:

                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_3:

                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_4:

                        break;
                    case MainMenu::MenuItem::TYPE::LEVEL_5:

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

void LevelSelectState::frameCalculator() {
    float center = Game::getGame()->getWindow()->getView().getCenter().x;
    float offset = Game::getGame()->getWindow()->getView().getSize().x / 2;
}

void LevelSelectState::generateFrame() {
    targetWindow->clear();

    sf::Texture texture;
    if (!texture.loadFromFile("Assets/Images/BG/bg.jpg"))
    {
        std::cerr<<"Error loading background!"<<std::endl;
    }
    sf::Sprite background(texture);
    targetWindow->draw(background);

    mainMenu.draw(targetWindow);

}


