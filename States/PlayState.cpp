//
// Created by Lorenzo Massa on 31/05/2020.
//

#include <cmath>
#include "PlayState.h"
#include "../Engine/Game.h"
#include "PauseState.h"



PlayState::PlayState(const std::shared_ptr<sf::RenderWindow>& targetWindow, int level) : GameState(targetWindow) {
    this->level = level;
    Game::getGame()->getMapHandler()->loadLevel(level);

    action = 0;
    clock = std::make_shared<sf::Clock>();
    clockEnemies = std::make_shared<sf::Clock>();
    directionClock = std::make_shared<sf::Clock>();
    combactClock = std::make_shared<sf::Clock>();

    sf::View tempView = targetWindow->getView();
    tempView.setCenter(tempView.getSize().x/2 - Game::getGame()->getHero()->sf::Sprite::getPosition().x,tempView.getSize().y/2);
    targetWindow->setView(tempView);

    AssetManager::initBackground(targetWindow,- Game::getGame()->getHero()->sf::Sprite::getPosition().x);
}

void PlayState::handleInput() {
    sf::Vector2f speed;

    sf::Event event{};
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
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up|| event.key.code == sf::Keyboard::Space) {
                if(Game::getGame()->getHero()->getSpeed().y==0.0f)
                    Game::getGame()->getHero()->jump();
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(-1.0f);
                //speed.x =10.0f*64.0f;
                speed= Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f( speed.x,speed.y));
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(1.0f);
                //speed.x =10.0f*64.0f; //Game::getGame()->getHero()->getSpeed();
                speed= Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f( speed.x,speed.y));
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(0.0f);

            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(0.0f);

            }
        } else if (event.type == sf::Event::MouseButtonPressed){
            switch(event.key.code) {
                case sf::Mouse::Left:
                    sf::Vector2i mousePosition = sf::Vector2i (sf::Mouse::getPosition(*targetWindow));
                    sf::Vector2f mouseWorldPosition = targetWindow->mapPixelToCoords(mousePosition);

                    mouseWorldPosition.x -= Game::getGame()->getHero()->getTexture()->getSize().x * Game::getGame()->getHero()->getScale().x/2.0f;
                    mouseWorldPosition.y -= Game::getGame()->getHero()->getTexture()->getSize().y * Game::getGame()->getHero()->getScale().y/2.0f;

                    //std::cout<<"Mouse Position X: "<<mousePosition.x<<" Y: "<<mousePosition.y<<std::endl;

                    std::shared_ptr<Bullet> b = Game::getGame()->getHero()->shot(mouseWorldPosition);
                    b->setFriendly(true);

                    if (Game::getGame()->getHero()->getAmmo() >= 0)
                            Game::getGame()->getMapHandler()->getMap()->addBullet(b);

                    break;

            }
        }
    }

    animationHero(Game::getGame()->getHero()->getDirection(), speed);

}

void PlayState::generateFrame() {


    sf::Vector2f move = isLegalMovement(Game::getGame()->getHero(),Game::getGame()->getHero()->move(sf::Vector2f(Game::getGame()->getHero()->getDirection(),
                                                                 1.0f),Game::getGame()->getClock()->getElapsedTime().asSeconds()));
    if(move.x != 0 || move.y != 0){
        Game::getGame()->getHero()->sf::Sprite::move(move);
        if(Game::getGame()->getHero()->sf::Sprite::getPosition().y > 16*64)
            Game::getGame()->killHero();
    }

    sf::View tempView = targetWindow->getView();

       if ((Game::getGame()->getHero()->getPosition().x - AssetManager::getXBackground() < 800 &&
                Game::getGame()->getHero()->getDirection() == -1) ||
           (AssetManager::getXBackground() + targetWindow->getSize().x - 800 <
                Game::getGame()->getHero()->getPosition().x && Game::getGame()->getHero()->getDirection() == 1)) {
           tempView.move(move.x, 0);
           targetWindow->setView(tempView);
       }
       else
           move.x = 0;

    float directionEnemy;

    for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies())
    {
        sf::Vector2f moveEnemy=sf::Vector2f(0,0);
        bool found;
        std::shared_ptr<Bullet> b= nullptr;

       if(enemy->getBehavior()=="patrol") {
           if (patrolClock()) {
               enemy->setDirection(-1.0f);
           } else {
               enemy->setDirection(1.0f);
           }

           found = enemy->patrol(Game::getGame()->getClock()->getElapsedTime().asSeconds(), enemy->getDirection(),
                                 sf::Vector2f(Game::getGame()->getHero()->getPosition()), &moveEnemy);
           moveEnemy = isLegalMovement(enemy,sf::Vector2f(moveEnemy));
           enemy->sf::Sprite::move(sf::Vector2f(moveEnemy));
           if(found)
           {
               enemy->setBehavior("fight");
           }
       }
       else if(enemy->getBehavior()=="fight")
       {
           b = enemy->fight(sf::Vector2f(Game::getGame()->getHero()->sf::Sprite::getPosition()),&moveEnemy,Game::getGame()->getClock()->getElapsedTime().asSeconds(),b);
           moveEnemy = isLegalMovement(enemy,sf::Vector2f(moveEnemy));
           enemy->sf::Sprite::move(sf::Vector2f(moveEnemy));

           if(b!= nullptr){
               if(fireClock(enemy->getWeapon()->getFireRate()))
               {
                   Game::getGame()->getMapHandler()->getMap()->addBullet(b);
               }
           }
       }
    }

    animationEnemies();

    checkBullets();

   targetWindow->clear();

   AssetManager::setBackground(targetWindow, move.x);

   generateMap();

   generateGUI(move.x);

   checkCollectables();

    if (Game::getGame()->getHero()->getClockPowerUp().getElapsedTime().asSeconds() > 10 && Game::getGame()->getHero()->isPowerUpState()){
        Game::getGame()->getHero()->removePowerUp();
    }

    targetWindow->draw(*Game::getGame()->getHero());

    checkFinished();

}

void PlayState::checkFinished(){
    if (checkCollision(Game::getGame()->getHero(), Game::getGame()->getMapHandler()->getMap()->getPortal()) &&
    Game::getGame()->getMapHandler()->getMap()->getEnemies().empty()){
        std::cout<<"Level completed!"<<std::endl;
        Game::getGame()->finishLevel(level);
    }

}

void PlayState::generateMap(){
    for(const auto& blocks : Game::getGame()->getMapHandler()->getMap()->getMatrix())
        targetWindow->draw(*blocks);
    for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies())
        targetWindow->draw(*enemy);
    for(const auto& collectable : Game::getGame()->getMapHandler()->getMap()->getCollectables())
        targetWindow->draw(*collectable);
    for(const auto& bullet : Game::getGame()->getMapHandler()->getMap()->getBullets())
        targetWindow->draw(*bullet);

    if(Game::getGame()->getMapHandler()->getMap()->getPortal() != nullptr)
        targetWindow->draw(*Game::getGame()->getMapHandler()->getMap()->getPortal());
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
    currentAmmoSprite.setPosition(line.getPosition().x + line.getSize().x + 50, line.getPosition().y - 5);
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

    sf::Text message;
    message.setFont(*AssetManager::font);
    message.setString(Game::getGame()->getHero()->getTypePowerUp());
    message.setCharacterSize(25);
    message.setPosition(AssetManager::getXBackground() + targetWindow->getView().getSize().x/2 - message.getLocalBounds().width/2, nCoins.getPosition().y+3);
    if(Game::getGame()->getHero()->isPowerUpState()){
        targetWindow->draw(message);
    }

}

void PlayState::animationHero(int direction, sf::Vector2f speed) {
    float speedClock = 0.1;

    if (clock->getElapsedTime().asSeconds()>speedClock && direction == 0) {
        if(Game::getGame()->getHero()->getStrTexture().back() == 'd'){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_1_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Idle_1_Reversed");
        }else{
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_1"));
            Game::getGame()->getHero()->setStrTexture("Idle_1");
        }

    }else if(clock->getElapsedTime().asSeconds()>speedClock && direction > 0){
        clock->restart();
        if(Game::getGame()->getHero()->getStrTexture() == "Run_6" || Game::getGame()->getHero()->getStrTexture() == "Idle_1"
            || Game::getGame()->getHero()->getStrTexture() == "Idle_1_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_1"));
            Game::getGame()->getHero()->setStrTexture("Run_1");
        } else if(Game::getGame()->getHero()->getStrTexture() == "Run_1"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_2"));
            Game::getGame()->getHero()->setStrTexture("Run_2");
        }else if(Game::getGame()->getHero()->getStrTexture() == "Run_2"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_3"));
            Game::getGame()->getHero()->setStrTexture("Run_3");
        } else if(Game::getGame()->getHero()->getStrTexture() == "Run_3"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_4"));
            Game::getGame()->getHero()->setStrTexture("Run_4");
        }else if(Game::getGame()->getHero()->getStrTexture() == "Run_4"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_5"));
            Game::getGame()->getHero()->setStrTexture("Run_5");
        }else if(Game::getGame()->getHero()->getStrTexture() == "Run_5"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_6"));
            Game::getGame()->getHero()->setStrTexture("Run_6");
        }

    }else if(clock->getElapsedTime().asSeconds()>speedClock && direction < 0){
        clock->restart();
        if(Game::getGame()->getHero()->getStrTexture() == "Run_6_Reversed" || Game::getGame()->getHero()->getStrTexture() == "Idle_1"
            || Game::getGame()->getHero()->getStrTexture() == "Idle_1_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_1_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_1_Reversed");
        } else if(Game::getGame()->getHero()->getStrTexture() == "Run_1_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_2_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_2_Reversed");
        }else if(Game::getGame()->getHero()->getStrTexture() == "Run_2_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_3_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_3_Reversed");
        } else if(Game::getGame()->getHero()->getStrTexture() == "Run_3_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_4_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_4_Reversed");
        }else if(Game::getGame()->getHero()->getStrTexture() == "Run_4_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_5_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_5_Reversed");
        }else if(Game::getGame()->getHero()->getStrTexture() == "Run_5_Reversed"){
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_6_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_6_Reversed");
        }
    }

}

void PlayState::animationEnemies(){
    float speedClock = 0.1;

    int i = 0;
    for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies()){
        i++;

        if(enemy->getBehaviorType() == "Wizard"){
            if (clockEnemies->getElapsedTime().asSeconds()>speedClock && enemy->getDirection() == 0) {
                if(enemy->getStrTexture().back() == 'd'){
                    enemy->setTexture(AssetManager::textures.at("Blue_Idle_1_Reversed"));
                    enemy->setStrTexture("Blue_Idle_1_Reversed");
                }else{
                    enemy->setTexture(AssetManager::textures.at("Blue_Idle_1"));
                    enemy->setStrTexture("Blue_Idle_1");
                }
            }
            if(clockEnemies->getElapsedTime().asSeconds()>speedClock && enemy->getDirection() > 0){
                clockEnemies->restart();
                if(enemy->getStrTexture() == "Blue_Run_6" || enemy->getStrTexture() == "Blue_Idle_1"
                   || enemy->getStrTexture() == "Blue_Idle_1_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_1"));
                    enemy->setStrTexture("Blue_Run_1");
                } else if(enemy->getStrTexture() == "Blue_Run_1"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_2"));
                    enemy->setStrTexture("Blue_Run_2");
                }else if(enemy->getStrTexture() == "Blue_Run_2"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_3"));
                    enemy->setStrTexture("Blue_Run_3");
                } else if(enemy->getStrTexture() == "Blue_Run_3"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_4"));
                    enemy->setStrTexture("Blue_Run_4");
                }else if(enemy->getStrTexture() == "Blue_Run_4"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_5"));
                    enemy->setStrTexture("Blue_Run_5");
                }else if(enemy->getStrTexture() == "Blue_Run_5"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_6"));
                    enemy->setStrTexture("Blue_Run_6");
                }else{
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_1"));
                    enemy->setStrTexture("Blue_Run_1");
                }

            }else if(clockEnemies->getElapsedTime().asSeconds()>speedClock && enemy->getDirection() < 0){
                clockEnemies->restart();
                if(enemy->getStrTexture() == "Blue_Run_6_Reversed" || enemy->getStrTexture() == "Blue_Idle_1"
                   || enemy->getStrTexture() == "Blue_Idle_1_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_1_Reversed"));
                    enemy->setStrTexture("Blue_Run_1_Reversed");
                } else if(enemy->getStrTexture() == "Blue_Run_1_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_2_Reversed"));
                    enemy->setStrTexture("Blue_Run_2_Reversed");
                }else if(enemy->getStrTexture() == "Blue_Run_2_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_3_Reversed"));
                    enemy->setStrTexture("Blue_Run_3_Reversed");
                } else if(enemy->getStrTexture() == "Blue_Run_3_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_4_Reversed"));
                    enemy->setStrTexture("Blue_Run_4_Reversed");
                }else if(enemy->getStrTexture() == "Blue_Run_4_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_5_Reversed"));
                    enemy->setStrTexture("Blue_Run_5_Reversed");
                }else if(enemy->getStrTexture() == "Blue_Run_5_Reversed"){
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_6_Reversed"));
                    enemy->setStrTexture("Blue_Run_6_Reversed");
                }else{
                    enemy->setTexture(AssetManager::textures.at("Blue_Run_1_Reversed"));
                    enemy->setStrTexture("Blue_Run_1_Reversed");
                }
            }


        }else if (enemy->getBehavior() == "Sentinel"){




        }else{




        }




    }
}


sf::Vector2f PlayState::isLegalMovement(const std::shared_ptr<GameCharacter>& entity, sf::Vector2f move){
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
    //da errore perchè non si controlla il massimo indice
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

bool PlayState::checkCollision(const std::shared_ptr<sf::Sprite>& entity1, const std::shared_ptr<sf::Sprite>& entity2){
    bool collision = false;

    sf::Vector2f entityPos = entity1->getPosition();
    sf::Vector2u entitySize = entity1->getTexture()->getSize();
    sf::Vector2f entityScale = entity1->getScale();

    entityPos.x += entitySize.x*entityScale.x/2.0f;
    entityPos.y += entitySize.y*entityScale.y/2.0f;

    float deltaX = entityPos.x - (entity2->getPosition().x + entity2->getTexture()->getSize().x * entity2->getScale().x /2.0f);
    float deltaY = entityPos.y - (entity2->getPosition().y + entity2->getTexture()->getSize().y * entity2->getScale().y /2.0f);
    float intersectionX = std::fabs(deltaX) - ((entitySize.x*entityScale.x/2) + (entity2->getTexture()->getSize().x*entity2->getScale().x/2.0f));
    float intersectionY = std::fabs(deltaY) - ((entitySize.y*entityScale.y/2) + (entity2->getTexture()->getSize().y*entity2->getScale().y/2.0f));

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

void PlayState::checkBullets(){
    int i=0, hp = 0;
    bool deleted = false, killedHero = false;
    for(const auto& bullet : Game::getGame()->getMapHandler()->getMap()->getBullets()){
        bullet->move(Game::getGame()->getClock()->getElapsedTime().asSeconds());
        deleted = false;
        if (!spriteInView(*bullet)){
            deleted = true;
            Game::getGame()->getMapHandler()->getMap()->removeBullet(i);
            //std::cout<<"Removed or view"<<std::endl;
        }else if(checkCollision(bullet, Game::getGame()->getHero()) && !bullet->isFriendly()) {
            deleted = true;
            hp = Game::getGame()->getHero()->receiveDamage(bullet->getDamage());
            Game::getGame()->getMapHandler()->getMap()->removeBullet(i);
            if(hp < 1){
                //Game::getGame()->killHero();
                killedHero = true;
            }
            //std::cout<<"Removed for hero"<<std::endl;
        }else{
            if(!deleted){
                for(const auto& enemy : Game::getGame()->getMapHandler()->getMap()->getEnemies()){
                    if(checkCollision(bullet, enemy) && bullet->isFriendly() && !deleted){
                        deleted = true;
                        hp = enemy->receiveDamage(bullet->getDamage());
                        //std::cout<<"Enemy hp: "<<hp<<std::endl;
                        if(hp < 1)
                            Game::getGame()->getMapHandler()->getMap()->removeEnemy(i);
                        Game::getGame()->getMapHandler()->getMap()->removeBullet(i);
                        //std::cout<<"Removed for enemy"<<std::endl;
                    }
                }
            }
            if(!deleted){
                for(const auto& block : Game::getGame()->getMapHandler()->getMap()->getMatrix()){
                    if(checkCollision(bullet, block) && !deleted){
                        deleted = true;
                        Game::getGame()->getMapHandler()->getMap()->removeBullet(i);
                        //std::cout<<"Removed for block"<<std::endl;
                    }
                }
            }

        }
        //std::cout<<"i: "<<i<<std::endl;
        i++;
    }

    if(killedHero)
        Game::getGame()->killHero();


}

bool PlayState::spriteInView(sf::Sprite sprite)
{
    sf::Vector2f viewSize(targetWindow->getView().getSize());
    sf::Vector2f viewCenter(targetWindow->getView().getCenter());

    sf::Vector2i spritePosition = sf::Vector2i (sprite.getPosition());

    return !(std::fabs(spritePosition.x - viewCenter.x) > viewSize.x / 2 ||
             std::fabs(spritePosition.y - viewCenter.y) > viewSize.y / 2);
}

int PlayState::getAction() const {
    return action;
}

void PlayState::setAction(int action) {
    PlayState::action = action;
}

const std::shared_ptr<sf::Clock> &PlayState::getClock() const {
    return clock;
}

void PlayState::setClock(const std::shared_ptr<sf::Clock> &clock) {
    PlayState::clock = clock;
}

const std::shared_ptr<sf::Clock> &PlayState::getClockEnemies() const {
    return clockEnemies;
}

void PlayState::setClockEnemies(const std::shared_ptr<sf::Clock> &clockEnemies) {
    PlayState::clockEnemies = clockEnemies;
}

bool PlayState::patrolClock() {
    if(directionClock->getElapsedTime().asSeconds()>3.0f)
    {
        if(directionClock->getElapsedTime().asSeconds()>6.0f)
            directionClock->restart();
        return true;
    }
    return false;
}

bool PlayState:: fireClock(float fireRate){
    if(combactClock->getElapsedTime().asSeconds()>1.0f/fireRate)
    {
        combactClock->restart();
        return true;
    }

    return false;
}