//
// Created by th3lo on 31/05/2020.
//

#include "PlayState.h"
#include "../Engine/Game.h"


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
            if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                //mainMenu.backward();
            if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                //mainMenu.forward();
            if(event.key.code == sf::Keyboard::Enter) {
                /*switch (mainMenu.getAction()) {
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
                }*/
            }
        }
    }
}

void PlayState::frameCalculator() {
    float center = Game::getGame()->getWindow()->getView().getCenter().x;
    float offset = Game::getGame()->getWindow()->getView().getSize().x / 2;
}

void PlayState::generateFrame() {
    targetWindow->clear(sf::Color(19, 24, 98));

    sf::Texture tileTexture;
    sf::Sprite tile;

    tileTexture.loadFromFile("src/Tiles/2.png");
    tile.setTexture(tileTexture);

    int m = Game::getGame()->getMapHandler()->getMap()->getM();
    int n = Game::getGame()->getMapHandler()->getMap()->getN();

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++){

            if (Game::getGame()->getMapHandler()->getMap()->getFromMatrix(i*m+j) == 'B'){
                tile.setPosition(j*32,i*32);
                tile.setTextureRect(sf::IntRect(0,0,32,32));
                targetWindow->draw(tile);
            }

        }
    }


}
