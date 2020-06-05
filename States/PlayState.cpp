//
// Created by Lorenzo Massa on 31/05/2020.
//

#include "PlayState.h"
#include "../Engine/Game.h"
#include "PauseState.h"



PlayState::PlayState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow) {
    action = 0;
}

void PlayState::handleInput() {
    float direction=0;

    sf::Event event;
    while(targetWindow->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        }
        else if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape) {
                Game::getGame()->getStateHandler()->addState(std::make_shared<PauseState>(targetWindow));
            }
            if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
                Game::getGame()->getHero()->jump();
            }
            if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                direction=-1;
            }
            if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                direction=1;
            }
        }
    }
    Game::getGame()->getHero()->move(sf::Vector2f(direction,1.0f),Game::getGame()->getClock()->getElapsedTime().asSeconds());
}

void PlayState::frameCalculator() {
    /* Moving the view
    sf::Vector2f pos = targetWindow->mapPixelToCoords(sf::Vector2i(0, 0));
    sf::View tempView = targetWindow->getView();
    tempView.move(-1.0f, 0);
    targetWindow->setView(tempView);*/
}

void PlayState::generateFrame() {
    targetWindow->clear();

    AssetManager::setBackground(targetWindow);

    generateMap();

    targetWindow->draw(*Game::getGame()->getHero());

}

void PlayState::generateMap(){
    for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix())
        targetWindow->draw(*blocks);
}

