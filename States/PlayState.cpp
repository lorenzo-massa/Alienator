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
    clockEnemies = std::make_shared<sf::Clock>();
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
    animationEnemies();

}

void PlayState::generateFrame() {

    sf::Vector2f move = isLegalMovement(Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(), 1.0f),Game::getGame()->getClock()->getElapsedTime().asSeconds()));
    if(move.x != 0 || move.y != 0)
        Game::getGame()->getHero()->sf::Sprite::move(move);

    sf::View tempView = targetWindow->getView();

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
    for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies())
        targetWindow->draw(*enemy);
    for(const auto& collectable : Game::getGame()->getMapHandler()->getMap()->getCollectables())
        targetWindow->draw(*collectable);
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

void PlayState::animationEnemies(){
    std::string texture = "";
    int i = 0;
    for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies()){
        i++;
        texture = enemy->getStrTexture();
        if(clockEnemies->getElapsedTime().asSeconds()>2 && texture.back() == '1') {
            texture.replace(texture.size() - 1, 1 , "2");
            enemy->setTexture(AssetManager::textures.at(texture));
            enemy->setStrTexture(texture);
            if(i == Game::getGame()->getMapHandler()->getMap()->getEnemies().size())
                clockEnemies->restart();
        }else if (clockEnemies->getElapsedTime().asSeconds()>0.05 && texture.back() == '2') {
            texture.replace(texture.size() - 1, 1 , "3");
            enemy->setTexture(AssetManager::textures.at(texture));
            enemy->setStrTexture(texture);
            if(i == Game::getGame()->getMapHandler()->getMap()->getEnemies().size())
                clockEnemies->restart();
        }else if (clockEnemies->getElapsedTime().asSeconds()>0.05 && texture.back() == '3') {
            texture.replace(texture.size() - 1, 1 , "1");
            enemy->setTexture(AssetManager::textures.at(texture));
            enemy->setStrTexture(texture);
            if(i == Game::getGame()->getMapHandler()->getMap()->getEnemies().size() )
                clockEnemies->restart();
        }
    }
}

sf::Vector2f PlayState::isLegalMovement(sf::Vector2f move){
    bool collision = false;
    sf::Vector2f moving = move;
    sf::Vector2f entityPos = Game::getGame()->getHero()->getPosition() + move;
    sf::Vector2u entitySize = Game::getGame()->getHero()->getTexture()->getSize();
    sf::Vector2f entityScale = Game::getGame()->getHero()->getScale();

    //Posizione nel centro della texture
    entityPos.x += entitySize.x*entityScale.x/2.0f;
    entityPos.y += entitySize.y*entityScale.y/2.0f;

    float deltaX;
    float deltaY;
    float intersectionX;
    float intersectionY;

    /* Qui sto provando a fare meno controlli (quindi controllo solo i due blocchi accanto a Hero per renderlo piè efficiente)
     * Mi da un errore di memoria quando cùtiro fuori i blocchi dalla matrice, se vuoi dare un occhiata... se no riguardo io
    int x = int(entityPos.x/64);
    int y = int(entityPos.y/64);

    std::cout<<x<<std::endl;
    std::cout<<y<<std::endl;


    sf::Sprite block;

    for(int i = x - 2; i++; i < x + 3){
        for(int j = y - 2; j++; i < y + 3){
            block = *(Game::getGame()->getMapHandler()->getMap()->getFromMatrix(i * Game::getGame()->getMapHandler()->getMap()->getM() * j));
            deltaX  = entityPos.x - (block.getPosition().x + block.getTexture()->getSize().x * block.getScale().x /2.0f);
            intersectionX = fabs(deltaX) - ((entitySize.x*entityScale.x/2) + (block.getTexture()->getSize().x*block.getScale().x/2.0f));
            deltaY  = entityPos.y - (block.getPosition().y + block.getTexture()->getSize().y * block.getScale().y /2.0f);
            intersectionY = fabs(deltaY) - ((entitySize.y*entityScale.y/2) + (block.getTexture()->getSize().y*block.getScale().y/2.0f));
            if(intersectionY < 0.0f && intersectionX < 0.0f){
                collision = true;
                std::cout<<"\n\nMove X: "<< move.x << " Y: "<<move.y<<std::endl;
                std::cout<<"Collision with: X: "<< block.getPosition().x/64 << " Y: "<<block.getPosition().y/64 << std::endl;
                if(intersectionX > intersectionY){
                    moving.x = 0;
                    if(deltaX > 0.0f){
                        std::cout<<"Left Collision!";
                    }else{
                        std::cout<<"Right Collision!";
                    }
                }
                else
                {
                    moving.y = 0;
                    if(deltaY > 0.0f){
                        std::cout<<"Top Collision!";
                    }else{
                        std::cout<<"Bottom Collision!";
                    }
                }
            }
        }
    }
    */


    for(const auto& block : Game::getGame()->getMapHandler()->getMap()->getMatrix()){
        deltaX  = entityPos.x - (block->getPosition().x + block->getTexture()->getSize().x * block->getScale().x /2.0f);
        intersectionX = fabs(deltaX) - ((entitySize.x*entityScale.x/2) + (block->getTexture()->getSize().x*block->getScale().x/2.0f));
        deltaY  = entityPos.y - (block->getPosition().y + block->getTexture()->getSize().y * block->getScale().y /2.0f);
        intersectionY = fabs(deltaY) - ((entitySize.y*entityScale.y/2) + (block->getTexture()->getSize().y*block->getScale().y/2.0f));
        if(intersectionY < 0.0f && intersectionX < 0.0f){
            collision = true;
            std::cout<<"\n\nMove X: "<< move.x << " Y: "<<move.y<<std::endl;
            std::cout<<"Collision with: X: "<< block->getPosition().x/64 << " Y: "<<block->getPosition().y/64 << std::endl;
            if(intersectionX > intersectionY){
                moving.x = 0;

                if(deltaX > 0.0f){
                    std::cout<<"Left Collision!";
                }else{
                    std::cout<<"Right Collision!";
                }
            }
        else
            {//saltino = differenza fra intersezione e gravità
             if(deltaY < 0.0f){//cambia se la collisione avviene sopra o sotto il personaggio
                 Game::getGame()->getHero()->sf::Sprite::move(0,moving.y+intersectionY);
                 Game::getGame()->getHero()->setSpeed(sf::Vector2f(Game::getGame()->getHero()->getSpeed().x,-98.0f*64.0f*Game::getGame()->getClock()->getElapsedTime().asSeconds()));
                 std::cout<<"Bottom Collision!";
             }
             else if(deltaY > 0.0f){
                 Game::getGame()->getHero()->sf::Sprite::move(0,moving.y-intersectionY);
                 Game::getGame()->getHero()->setSpeed(sf::Vector2f(Game::getGame()->getHero()->getSpeed().x,-98.0f*64.0f*Game::getGame()->getClock()->getElapsedTime().asSeconds()));
                 std::cout<<"Top Collision!";
             }
             moving.y = 0;

            }
        }
    }


    if(collision){
        Game::getGame()->getHero()->setSpeed(sf::Vector2f(0,0));
        std::cout<<"Moving X: "<<moving.x<<" Y: "<<moving.y<<std::endl;
    }



    return moving;
}
