//
// Created by th3lo on 31/05/2020.
//

#include "PlayState.h"
#include "../Engine/Game.h"
#include "PauseState.h"


PlayState::PlayState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow) {
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
                Game::getGame()->getHero()->getSprite()->move(0, -1.0f);
            }
            if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                Game::getGame()->getHero()->getSprite()->move(0, 1.0f);
            }
            if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                /*int nextPos=Game::getGame()->getHero()->getPos()-1;
                if(Game::getGame()->getHero()->isLegalMovement(Game::getGame()->getMapHandler()->getMap()->getFromMatrix(nextPos))) {
                    Game::getGame()->getHero()->getSprite()->move(-15.0f, 0);
                    Game::getGame()->getHero()->setPos(nextPos);
                }*/
                direction=-1;
            }
            if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {

                /*if (Game::getGame()->getHero()->getSprite()->getLocalBounds()
                    notDetected=false;*/
               direction=1;

            }
            Game::getGame()->getHero()->move(sf::Vector2f(direction,0));
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
                tile.setPosition(j*32,i*32);
                tile.setTextureRect(sf::IntRect(0,0,32,32));
                targetWindow->draw(tile);
            } else if (Game::getGame()->getMapHandler()->getMap()->getFromMatrix(i*m+j) == 'P'){
                Game::getGame()->createHero(i*32+j);
                Game::getGame()->getHero()->setPos(i*32+j);
                Game::getGame()->getHero()->init(sf::Vector2f(j*32,i*32),sf::Vector2f(20,30));
                Game::getGame()->getMapHandler()->getMap()->setMatrixValue(i*m+j, '.');
            }

        }
    }
}

