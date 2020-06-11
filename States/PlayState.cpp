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
                Game::getGame()->getHero()->jump();
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(-1.0f);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f(8.0f * 64.0f, speed.y));
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(1.0f);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f(8.0f * 64.0f, speed.y));
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

void PlayState::frameCalculator() {

}

void PlayState::generateFrame() {

    sf::Vector2f move = Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(), 1.0f),
                                                Game::getGame()->getClock()->getElapsedTime().asSeconds());
    Game::getGame()->getHero()->sf::Sprite::move(move);
    //isLegalMovement(*(Game::getGame()->getHero()),move);

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
    if(Game::getGame()->getHero()->getStrTexture() == "Idle_1"){
        Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_2"));
        Game::getGame()->getHero()->setStrTexture("Idle_2");
    }else if (Game::getGame()->getHero()->getStrTexture() == "Idle_2"){
        Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_3"));
        Game::getGame()->getHero()->setStrTexture("Idle_3");
    }else if (Game::getGame()->getHero()->getStrTexture() == "Idle_3"){
        Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_1"));
        Game::getGame()->getHero()->setStrTexture("Idle_1");
    }
}

/*void PlayState::isLegalMovement(Hero entity,sf::Vector2f move){

    sf::Vector2f entityPos;
    entityPos.x=(entity.getPosition().x)+move.x;
    entityPos.y=(entity.getPosition().y)+move.y;
    sf::Vector2f entitySize;
    entitySize.x=(entity.getTextureRect().width)/ 2.0f;
    entitySize.y=(entity.getTextureRect().height)/2.0f;
    sf::Vector2f blockPos;
    sf::Vector2f blockSize;

    bool found=false;

    float deltaX;
    float deltaY;

    float intersectionX;
    float intersectionY;

    for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix()) {
        blockPos.x = blocks->getPosition().x;
        blockPos.y = blocks->getPosition().y;

        blockSize.x = (blocks->getTextureRect().width )/ 2.0f;
        blockSize.y= (blocks->getTextureRect().height)/2.0f;

        deltaX = blockPos.x - entityPos.x;
        deltaY = blockPos.y - entityPos.y;

        intersectionX = abs(deltaX) - (blockSize.x + entitySize.x);
        intersectionY = abs(deltaY) - (blockSize.y + entitySize.y);

        if (intersectionX < 0.0f && intersectionY<0.0f)
        {
            if(intersectionX>intersectionY)
            {
                if(deltaX>0.0f)
                {
                    entity.sf::Sprite::move(intersectionX+abs(move.x),0.0f);
                }
                else
                {
                    entity.sf::Sprite::move(-intersectionX-abs(move.x),0.0f);
                }
            }
            else
            {
                if(deltaY>0.0f){
                    entity.sf::Sprite::move(0.0f,intersectionY+abs(move.y));
                }
                else
                {
                    entity.sf::Sprite::move(0.0f,-intersectionY-abs(move.y));
                }
            }

        }

        std::cout<<intersectionY<<"   ||    ";
        std::cout<<intersectionX<<"\n";
    }
}*/