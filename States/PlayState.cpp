//
// Created by th3lo on 31/05/2020.
//

#include "PlayState.h"
#include "../Engine/Game.h"
#include "PauseState.h"


PlayState::PlayState(std::shared_ptr<sf::RenderWindow> targetWindow) : GameState(targetWindow) {
}

void PlayState::handleInput() {
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
                Game::getGame()->getHero()->setDirection(-1);
                Game::getGame()->getHero()->move(Game::getGame()->getHero()->getPosX(),Game::getGame()->getHero()->getPosY(),Game::getGame()->getHero()->getSpeed(),Game::getGame()->getHero()->getDirection());
            }
            if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->getSprite()->move(1.3f, 0);
            }
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

    sf::Texture texture;
    if (!texture.loadFromFile("src/BG/bg.jpg"))
    {
        std::cerr<<"Error loading background!"<<std::endl;
    }
    sf::Sprite background(texture);
    targetWindow->draw(background);

    generateMap();

    targetWindow->draw(*Game::getGame()->getHero()->getSprite());

}

void PlayState::generateMap(){
    sf::Texture tileTexture;
    sf::Sprite tile;

    tileTexture.loadFromFile("src/Tiles/2.png");
    tile.setTexture(tileTexture);

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
                Game::getGame()->createHero(j*32,i*32);
                Game::getGame()->getHero()->init(sf::Vector2f(j*32,i*32),sf::Vector2f(20,30));
                Game::getGame()->getMapHandler()->getMap()->setMatrixValue(i*m+j, '.');
            }

        }
    }
}

