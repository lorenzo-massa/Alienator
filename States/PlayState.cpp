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
    float j=0;
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
                j=Game::getGame()->getHero()->jump();
            }
            if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                direction=-1;
            }
            if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                direction=1;
            }
            Game::getGame()->getHero()->move(sf::Vector2f(direction,j));
        }
    }
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

    std::cout<<Game::getGame()->getClock()->getElapsedTime().asMilliseconds()<<std::endl;

    targetWindow->draw(*Game::getGame()->getHero()->getSprite());

}

void PlayState::generateMap(){

    sf::Texture tileTexture;
    sf::Sprite tile;

    tile.setTexture(AssetManager::textures.at("2"));

    int n = Game::getGame()->getMapHandler()->getMap()->getN();
    int m = Game::getGame()->getMapHandler()->getMap()->getM();


    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++){

            if (Game::getGame()->getMapHandler()->getMap()->getFromMatrix(i*m+j) == 'B'){
                tile.setPosition(j*64,i*64);
                tile.setTextureRect(sf::IntRect(0,0,64,64));

                targetWindow->draw(tile);
            } else if (Game::getGame()->getMapHandler()->getMap()->getFromMatrix(i*m+j) == 'P'){
                Game::getGame()->createHero(i*64,j*64);

                Game::getGame()->getHero()->init(sf::Vector2f(j*64,i*64),sf::Vector2f(2,2));
                Game::getGame()->getMapHandler()->getMap()->setMatrixValue(i*m+j, '.');
            }

        }
    }
}

