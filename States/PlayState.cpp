//
// Created by Lorenzo Massa on 31/05/2020.
//

#include "PlayState.h"
#include "../Engine/Game.h"
#include "PauseState.h"
//#include <cmath>



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

    sf::Vector2f move = Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(), 1.0f),
                                                Game::getGame()->getClock()->getElapsedTime().asSeconds());

    sf::View tempView = targetWindow->getView();
    //
   // if(isLegalMovement()
    if ((Game::getGame()->getHero()->getPosition().x  - AssetManager::getXBackground() < 500 && Game::getGame()->getHero()->getDirection() == -1) ||
        (AssetManager::getXBackground() + targetWindow->getSize().x - 500 < Game::getGame()->getHero()->getPosition().x && Game::getGame()->getHero()->getDirection() == 1)) {
        tempView.move(move.x, 0);
        targetWindow->setView(tempView);
    } else
        move.x = 0;

    targetWindow->clear();

    AssetManager::setBackground(targetWindow, move.x);

    generateMap();

    generateGUI(move.x);

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


/*bool isLegalMovement(GameCharacter& entity,sf::Vector2f move){

    sf::Vector2f entityPos;
    entityPos.x=entity.getPosition().x+move.x;
    entityPos.y=entity.getPosition().y+move.y;
    sf::Vector2f entitySize=entity.getScale()/2.0f;
    sf::Vector2f blockPos;
    sf::Vector2f blockSize;

    float deltaX;
    float deltaY;

    float intersectionX;
    float intersectionY;

    for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix()) {
        blockPos=blocks->getPosition();
        blockSize=blocks->getScale()/2.0f;

        deltaX=blockPos.x-entityPos.x;
        deltaY= blockPos.y-entityPos.y;

        intersectionX=abs(deltaX)-(blockSize.x+entitySize.x);
        intersectionY=abs(deltaY)-(blockSize.y+entitySize.y);

        if(intersectionX<0.0f && intersectionY<0.0f)
            return true;
        else
            return false;

    }
}*/