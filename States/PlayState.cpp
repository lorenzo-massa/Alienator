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
    sf::Vector2f speed;

    sf::Event event;
    while (targetWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
            AssetManager::setBackground(targetWindow, 0);
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                Game::getGame()->getStateHandler()->addState(std::make_shared<PauseState>(targetWindow));
            }
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
                Game::getGame()->getHero()->jump();
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(-1);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f(8 * 64, speed.y));
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(1);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f(8 * 64, speed.y));
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(0);
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(0);
            }
        }
    }

}

void PlayState::frameCalculator() {

}

void PlayState::generateFrame() {

    float xT = Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(), 1.0f),
                                                Game::getGame()->getClock()->getElapsedTime().asSeconds());

    sf::View tempView = targetWindow->getView();
    //
    if ((Game::getGame()->getHero()->getPosition().x  - AssetManager::getXBackground() < 500 && Game::getGame()->getHero()->getDirection() == -1) ||
        (AssetManager::getXBackground() + targetWindow->getSize().x - 500 < Game::getGame()->getHero()->getPosition().x && Game::getGame()->getHero()->getDirection() == 1)) {
        tempView.move(xT, 0);
        targetWindow->setView(tempView);
    } else
        xT = 0;

    targetWindow->clear();

    AssetManager::setBackground(targetWindow, xT);

    generateMap();

    generateGUI(xT);

    targetWindow->draw(*Game::getGame()->getHero());

}

void PlayState::generateMap(){
    for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix())
        targetWindow->draw(*blocks);
}


void PlayState::generateGUI(float& xT){
    //Health
    sf::RectangleShape line(sf::Vector2f(104, 15));
    line.setFillColor(sf::Color::Transparent);
    line.setOutlineThickness(2);
    line.setOutlineColor(sf::Color::White);
    line.setPosition(AssetManager::getXBackground() + 100,50);

    sf::RectangleShape health(sf::Vector2f(Game::getGame()->getHero()->getHealthPoint(), 11));
    health.setFillColor(sf::Color::Red);
    health.setPosition(AssetManager::getXBackground() + 102,52);

    //Munitions
    sf::Sprite currentAmmoSprite;
    currentAmmoSprite.setTexture(AssetManager::textures.at("MUNITIONS"));
    currentAmmoSprite.setPosition(health.getPosition().x + health.getSize().x + 50, health.getPosition().y - 5);
    currentAmmoSprite.setScale(0.05,0.05);

    sf::Text nMunitions;
    nMunitions.setFont(*AssetManager::font);
    nMunitions.setString(std::to_string(Game::getGame()->getHero()->getAmmo()));
    nMunitions.setCharacterSize(20);
    nMunitions.setPosition(currentAmmoSprite.getPosition().x + 35, currentAmmoSprite.getPosition().y);



    targetWindow->draw(line);
    targetWindow->draw(health);
    targetWindow->draw(currentAmmoSprite);
    targetWindow->draw(nMunitions);
}


/*bool isLegalMovement(){
    float heroPosY=Game::getGame()->getHero()->getPosition().y+Game::getGame()->getHero()->getGlobalBounds().height;
    float blockPosY=Game::getGame()->getMapHandler()->
    if(heroPosY+8*64*direction==)

}*/