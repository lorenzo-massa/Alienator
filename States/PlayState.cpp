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

    sf::Vector2f move = isLegalMovement(Game::getGame()->getHero(),Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(),
                                                                 1.0f),Game::getGame()->getClock()->getElapsedTime().asSeconds()));
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
       
       checkCollectables();

    targetWindow->draw(*Game::getGame()->getHero());

}

void PlayState::generateMap(){
    for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix())
        targetWindow->draw(*blocks);
    for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies())
        targetWindow->draw(*enemy);
    for(const auto& collectable : Game::getGame()->getMapHandler()->getMap()->getCollectables())
        targetWindow->draw(*collectable);
    //for(const auto& bullet : Game::getGame()->getMapHandler()->getMap()->getBullets())
     //   targetWindow->draw(*bullet);
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

sf::Vector2f PlayState::isLegalMovement(std::shared_ptr<GameCharacter> entity, sf::Vector2f move){
    sf::Vector2f moving = move;
    sf::Vector2f entityPos = entity->getPosition();
    sf::Vector2u entitySize = entity->getTexture()->getSize();
    sf::Vector2f entityScale = entity->getScale();

    entityPos.x += entitySize.x*entityScale.x/2.0f;
    entityPos.y += entitySize.y*entityScale.y/2.0f;

    float deltaX;
    float deltaY;
    float intersectionX;
    float intersectionY;

    int rightCollision = 0;
    int leftCollision = 0;
    int bottomtCollision = 0;
    int topCollision = 0;

    bool rightCollisionBool = false;
    bool leftCollisionBool = false;
    bool bottomtCollisionBool = false;
    bool topCollisionBool = false;


/*
    // Qui sto provando a fare meno controlli (quindi controllo solo i due blocchi accanto a Hero per renderlo piè efficiente)
    int x = int(entityPos.x/64);
    int y = int(entityPos.y/64);


    if(y < 8)
        y = 8;
    if(x < 8)
        x = 8;

    std::shared_ptr<sf::Sprite> block;

    for(int i = x - 8; i < x + 9; i++){
        for(int j = y - 8; j < y + 9; j++){

            //std::cout<<i * Game::getGame()->getMapHandler()->getMap()->getN() + j<<std::endl;

            std::cout<<"\n1";
            block = Game::getGame()->getMapHandler()->getMap()->getFromMatrix(i * Game::getGame()->getMapHandler()->getMap()->getN() + j);
            std::cout<<"2";

            deltaX  = entityPos.x - (block->getPosition().x + block->getTexture()->getSize().x * block->getScale().x /2.0f);
            intersectionX = fabs(deltaX) - ((entitySize.x*entityScale.x/2) + (block->getTexture()->getSize().x*block->getScale().x/2.0f));
            deltaY  = entityPos.y - (block->getPosition().y + block->getTexture()->getSize().y * block->getScale().y /2.0f);
            intersectionY = fabs(deltaY) - ((entitySize.y*entityScale.y/2) + (block->getTexture()->getSize().y*block->getScale().y/2.0f));


            if(intersectionY < 0.0f && intersectionX < 0.0f){

                rightCollisionBool = false;
                leftCollisionBool = false;
                bottomtCollisionBool = false;
                topCollisionBool = false;

                if(intersectionX > intersectionY){
                    if(deltaX > 0.0f){
                        leftCollision++;
                        leftCollisionBool = true;
                    }else{
                        rightCollision++;
                        rightCollisionBool = true;
                    }
                }
                else{
                     if(deltaY < 0.0f){
                         bottomtCollision++;
                         bottomtCollisionBool = true;
                     }else{
                         topCollision++;
                         topCollisionBool = true;
                     }
                }

                if(leftCollision == 1 && leftCollisionBool){
                    moving.x -= intersectionX;
                    Game::getGame()->getHero()->setSpeed(sf::Vector2f(0,Game::getGame()->getHero()->getSpeed().y));
                }

                if(rightCollision == 1 && rightCollisionBool){
                    moving.x += intersectionX;
                    Game::getGame()->getHero()->setSpeed(sf::Vector2f(0,Game::getGame()->getHero()->getSpeed().y));
                }

                if(topCollision == 1 && topCollisionBool){
                    moving.y -= intersectionY;
                    Game::getGame()->getHero()->setSpeed(sf::Vector2f(Game::getGame()->getHero()->getSpeed().x,0));
                }

                if(bottomtCollision == 1 && bottomtCollisionBool){
                    moving.y += intersectionY;
                    Game::getGame()->getHero()->setSpeed(sf::Vector2f(Game::getGame()->getHero()->getSpeed().x,0));
                }

            }
        }
    }

*/

    for(const auto& block : Game::getGame()->getMapHandler()->getMap()->getMatrix()){
        deltaX  = entityPos.x + moving.x - (block->getPosition().x + block->getTexture()->getSize().x * block->getScale().x /2.0f);
        intersectionX = fabs(deltaX) - ((entitySize.x*entityScale.x/2) + (block->getTexture()->getSize().x*block->getScale().x/2.0f));
        deltaY  = entityPos.y + moving.y - (block->getPosition().y + block->getTexture()->getSize().y * block->getScale().y /2.0f);
        intersectionY = fabs(deltaY) - ((entitySize.y*entityScale.y/2) + (block->getTexture()->getSize().y*block->getScale().y/2.0f));


        if(intersectionY < 0.0f && intersectionX < 0.0f){ //se entra qui collide con un blocco

            rightCollisionBool = false;
            leftCollisionBool = false;
            bottomtCollisionBool = false;
            topCollisionBool = false;

            //std::cout<<"\n\nMove X: "<< move.x << " Y: "<<move.y<<std::endl;
            //std::cout<<"Collision with: X: "<< block->getPosition().x/64 << " Y: "<<block->getPosition().y/64 << std::endl;

            if(intersectionX > intersectionY){
                if(deltaX > 0.0f){
                    leftCollision++;
                    leftCollisionBool = true;
                    //std::cout<<"Left Collision!";
                }else{
                    rightCollision++;
                    rightCollisionBool = true;
                    //std::cout<<"Right Collision!";
                }
            }
            else{
                 if(deltaY < 0.0f){
                     bottomtCollision++;
                     bottomtCollisionBool = true;
                     //std::cout<<"Bottom Collision!";
                 }else{
                     topCollision++;
                     topCollisionBool = true;
                     //std::cout<<"Top Collision!";
                 }
            }

            if(leftCollision == 1 && leftCollisionBool){
                moving.x -= intersectionX;
                entity->setSpeed(sf::Vector2f(0,entity->getSpeed().y));
            }

            if(rightCollision == 1 && rightCollisionBool){
                moving.x += intersectionX;
                entity->setSpeed(sf::Vector2f(0,entity->getSpeed().y));
            }

            if(topCollision == 1 && topCollisionBool){
                moving.y -= intersectionY;
                entity->setSpeed(sf::Vector2f(entity->getSpeed().x,0));
            }

            if(bottomtCollision == 1 && bottomtCollisionBool){
                moving.y += intersectionY;
                entity->setSpeed(sf::Vector2f(entity->getSpeed().x,0));
            }

        }

    }

    /*
    if(leftCollision > 0 || rightCollision > 0 || topCollision > 0 || bottomtCollision > 0){
        std::cout<<"\nnCollisions: " << leftCollision + rightCollision + topCollision + bottomtCollision<<std::endl;
        std::cout<<"Moving X: "<<moving.x<<" Y: "<<moving.y<<std::endl;

    }
    */
    return moving;
}

bool PlayState::checkCollision(std::shared_ptr<sf::Sprite> entity1, std::shared_ptr<sf::Sprite> entity2){
    bool collision = false;

    sf::Vector2f entityPos = entity1->getPosition();
    sf::Vector2u entitySize = entity1->getTexture()->getSize();
    sf::Vector2f entityScale = entity1->getScale();

    entityPos.x += entitySize.x*entityScale.x/2.0f;
    entityPos.y += entitySize.y*entityScale.y/2.0f;

    float deltaX = entityPos.x - (entity2->getPosition().x + entity2->getTexture()->getSize().x * entity2->getScale().x /2.0f);
    float deltaY = entityPos.y - (entity2->getPosition().y + entity2->getTexture()->getSize().y * entity2->getScale().y /2.0f);
    float intersectionX = fabs(deltaX) - ((entitySize.x*entityScale.x/2) + (entity2->getTexture()->getSize().x*entity2->getScale().x/2.0f));
    float intersectionY = fabs(deltaY) - ((entitySize.y*entityScale.y/2) + (entity2->getTexture()->getSize().y*entity2->getScale().y/2.0f));

    if(intersectionY < 0.0f && intersectionX < 0.0f){
        collision = true;
    }

    return collision;
}


void PlayState::checkCollectables(){
    int i=0;
    for(const auto& collectable : Game::getGame()->getMapHandler()->getMap()->getCollectables()){
        if(checkCollision(collectable, Game::getGame()->getHero()))
            collectable->notifyObservers(i);
        i++;
    }
}
