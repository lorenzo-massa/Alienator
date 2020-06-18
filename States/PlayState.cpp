//
// Created by Lorenzo Massa on 31/05/2020.
//

#include <cmath>
#include "PlayState.h"
#include "../Engine/Game.h"
#include "PauseState.h"
//#include <cmath>



PlayState::PlayState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow) {
    action = 0;
    clock = std::make_shared<sf::Clock>();
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
                Game::getGame()->save();
                Game::getGame()->getStateHandler()->addState(std::make_shared<PauseState>(targetWindow));
            }
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
                if(Game::getGame()->getHero()->getSpeed().y==0.0f)
                    Game::getGame()->getHero()->jump();
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(-1.0f);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f( speed.x,speed.y));
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(1.0f);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f( speed.x,speed.y));
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(0.0f);

            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(0.0f);

            }
        }
    }

    animationHero(Game::getGame()->getHero()->getDirection(), speed);

}

void PlayState::generateFrame() {

    sf::Vector2f move = Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(), 1.0f),
                                                Game::getGame()->getClock()->getElapsedTime().asSeconds());

    move=isLegalMovement(*(Game::getGame()->getHero()),move);
    Game::getGame()->getHero()->sf::Sprite::move(move);

    sf::View tempView = targetWindow->getView();
    //

       if ((Game::getGame()->getHero()->getPosition().x - AssetManager::getXBackground() < 500 &&
            Game::getGame()->getHero()->getDirection() == -1) ||
           (AssetManager::getXBackground() + targetWindow->getSize().x - 500 <
            Game::getGame()->getHero()->getPosition().x && Game::getGame()->getHero()->getDirection() == 1)) {
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

    //Coins
    sf::Sprite currentCoinsSprite;
    currentCoinsSprite.setTexture(AssetManager::textures.at("COINS"));
    currentCoinsSprite.setPosition(currentAmmoSprite.getPosition().x + 80, currentAmmoSprite.getPosition().y - 3);
    currentCoinsSprite.setScale(0.06,0.06);

    sf::Text nCoins;
    nCoins.setFont(*AssetManager::font);
    nCoins.setString(std::to_string(Game::getGame()->getHero()->getCoins()));
    nCoins.setCharacterSize(20);
    nCoins.setPosition(currentCoinsSprite.getPosition().x + 35, currentCoinsSprite.getPosition().y + 3);



    targetWindow->draw(line);
    targetWindow->draw(health);
    targetWindow->draw(currentAmmoSprite);
    targetWindow->draw(nMunitions);
    targetWindow->draw(currentCoinsSprite);
    targetWindow->draw(nCoins);
}

void PlayState::animationHero(int direction, sf::Vector2f speed){
    if(clock->getElapsedTime().asSeconds()>2 && Game::getGame()->getHero()->getStrTexture() == "Idle_1") {
        Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_2"));
        Game::getGame()->getHero()->setStrTexture("Idle_2");
        clock->restart();
    }
    else if (clock->getElapsedTime().asSeconds()>0.05 && Game::getGame()->getHero()->getStrTexture() == "Idle_2") {
        Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_3"));
        Game::getGame()->getHero()->setStrTexture("Idle_3");
        clock->restart();
    } else if (clock->getElapsedTime().asSeconds()>0.05 && Game::getGame()->getHero()->getStrTexture() == "Idle_3") {
        Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_1"));
        Game::getGame()->getHero()->setStrTexture("Idle_1");
        clock->restart();
    }
}

sf::Vector2f PlayState::isLegalMovement(sf::Sprite entity,sf::Vector2f move){

    sf::Vector2f entityPos;
    entityPos.x=(entity.getPosition().x)+move.x;
    entityPos.y=(entity.getPosition().y)+move.y;
   // sf::Vector2u entitySize=entity.getTexture()->getSize();

    /*sf::Vector2f blockPos;
    sf::Vector2f blockSize;

    float deltaX;
    float deltaY;

    float intersectionX;
    float intersectionY;

   for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix()) {
        blockPos.x = blocks->getPosition().x;
        blockPos.y = blocks->getPosition().y;

        blockSize.x = (float) (blocks->getTextureRect().width)*blocks->getScale().x;
        blockSize.y= (float) (blocks->getTextureRect().height)*blocks->getScale().x;

        deltaX = blockPos.x - entityPos.x;
        deltaY = blockPos.y - entityPos.y;

        if(deltaX<(blockSize.x+entitySize.x)/2 && deltaY<(blockSize.y+entitySize.y)/2)
        {

        }
    }*/

    if(entityPos.y>500.0f)
   {
       Game::getGame()->getHero()->setSpeed(sf::Vector2f(Game::getGame()->getHero()->getSpeed().x,0.0f));
       entity.setPosition(entity.getPosition().x,500.0f);
       move.y=0;
   }
    return move;
}