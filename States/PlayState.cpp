//
// Created by Lorenzo Massa on 31/05/2020.
//

#include <cmath>
#include "PlayState.h"


PlayState::PlayState(const std::shared_ptr<sf::RenderWindow> &targetWindow, int level) : GameState(targetWindow) {
    this->level = level;

    Game::getGame()->getMap()->reset();

    Game::getGame()->getMap()->loadLevel(level);

    action = 0;

    sf::View tempView = targetWindow->getView();
    tempView.setCenter(tempView.getSize().x / 2 - Game::getGame()->getHero()->sf::Sprite::getPosition().x,
                       tempView.getSize().y / 2);
    targetWindow->setView(tempView);

    AssetManager::initBackground(targetWindow, -Game::getGame()->getHero()->sf::Sprite::getPosition().x);

    registerObserver(&(*Game::getGame()->getAchievements()));

    achievementsClock = std::make_shared<sf::Clock>();

    achievementUnlocked = false;
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
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up ||
                event.key.code == sf::Keyboard::Space) {
                if (Game::getGame()->getHero()->getSpeed().y == 0.0f){
                    Game::getGame()->getHero()->jump();
                    bool unlocked = false;
                    EVENT e = EVENT::JUMP;
                    notifyObservers(e, unlocked);
                    if(unlocked)
                        showAchievement(e);

                }
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(-1.0f);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f(speed.x, speed.y));
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(1.0f);
                speed = Game::getGame()->getHero()->getSpeed();
                Game::getGame()->getHero()->setSpeed(sf::Vector2f(speed.x, speed.y));
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                Game::getGame()->getHero()->setDirection(0);

            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                Game::getGame()->getHero()->setDirection(0);

            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            switch (event.key.code) {
                case sf::Mouse::Left:
                    sf::Vector2i mousePosition = sf::Vector2i(sf::Mouse::getPosition(*targetWindow));
                    sf::Vector2f mouseWorldPosition = targetWindow->mapPixelToCoords(mousePosition);

                    mouseWorldPosition.x -= Game::getGame()->getHero()->getTexture()->getSize().x *
                                            Game::getGame()->getHero()->getScale().x / 2.0f;
                    mouseWorldPosition.y -= Game::getGame()->getHero()->getTexture()->getSize().y *
                                            Game::getGame()->getHero()->getScale().y / 2.0f;

                    if (Game::getGame()->getHero()->fireClock(Game::getGame()->getHero()->getWeapon()->getFireRate()*(Game::getGame()->getHero()->getFireRateBoost()))){
                        std::shared_ptr<Bullet> b = Game::getGame()->getHero()->shot(mouseWorldPosition);
                        b->setFriendly(true);
                        if (Game::getGame()->getHero()->getAmmo() >= 0)
                            Game::getGame()->getMap()->addBullet(b);
                            bool unlocked = false;
                            EVENT e = EVENT::BULLET_SHOT;
                            notifyObservers(e, unlocked);
                            if(unlocked)
                                showAchievement(e);

                        }
                    break;

            }
        }
        /*}else if (event.type == sf::Event::MouseButtonReleased) {
            switch (event.key.code) {
                case sf::Mouse::Left:
                    Game::getGame()->getHero()->setWeaponHit(false);
                    break;
            }
        }*/

    }

    animationHero(Game::getGame()->getHero()->getDirection(), speed);

}

void PlayState::generateFrame() {


    sf::Vector2f move ;
    move = isLegalMovement(Game::getGame()->getHero(), Game::getGame()->getHero()->move(Game::getGame()->getClock()->getElapsedTime().asSeconds()));

    if (move.x != 0 || move.y != 0) {
        Game::getGame()->getHero()->sf::Sprite::move(move);
        if (Game::getGame()->getHero()->sf::Sprite::getPosition().y > 16 * 64){
            Game::getGame()->killHero();

            bool unlocked = false;
            EVENT e = EVENT::FALL;
            notifyObservers(e, unlocked);
            if(unlocked)
                showAchievement(e);
        }
    }

    sf::View tempView = targetWindow->getView();

    if ((Game::getGame()->getHero()->getPosition().x - AssetManager::getXBackground() < 800 &&
         (Game::getGame()->getHero()->getDirection() == -1
          || (Game::getGame()->getHero()->getDirection() == 0 && Game::getGame()->getHero()->getSpeed().x != 0)))
        ||
        (AssetManager::getXBackground() + targetWindow->getSize().x - 800 < Game::getGame()->getHero()->getPosition().x
         && (Game::getGame()->getHero()->getDirection() == 1 ||
             (Game::getGame()->getHero()->getDirection() == 0 && Game::getGame()->getHero()->getSpeed().x != 0)))) {
        tempView.move(move.x, 0);
        targetWindow->setView(tempView);
    } else
        move.x = 0;

    behaviorChanger();

    animationEnemies();

    checkBullets();

    targetWindow->clear();

    AssetManager::setBackground(targetWindow, move.x);

    generateMap();

    generateGUI(move.x);

    checkCollectables();

    if (Game::getGame()->getHero()->getClockPowerUp().getElapsedTime().asSeconds() > 10 &&
        Game::getGame()->getHero()->isPowerUpState()) {
        Game::getGame()->getHero()->removePowerUp();
    }

    targetWindow->draw(*Game::getGame()->getHero());

    checkFinished();

}

void PlayState::checkFinished() {
    if (checkCollision(Game::getGame()->getHero(), Game::getGame()->getMap()->getPortal()) &&
        Game::getGame()->getMap()->getEnemies().empty()) {
        std::cout << "Level completed!" << std::endl;
        Game::getGame()->finishLevel(level);
    }

}

void PlayState::generateMap() {
    for (const auto &blocks : Game::getGame()->getMap()->getMatrix())
        targetWindow->draw(*blocks);
    for (const auto &enemy : Game::getGame()->getMap()->getEnemies())
        targetWindow->draw(*enemy);
    for (const auto &collectable : Game::getGame()->getMap()->getCollectables())
        targetWindow->draw(*collectable);
    for (const auto &bullet : Game::getGame()->getMap()->getBullets())
        targetWindow->draw(*bullet);

    if (Game::getGame()->getMap()->getPortal() != nullptr)
        targetWindow->draw(*Game::getGame()->getMap()->getPortal());
}


void PlayState::generateGUI(float &xT) {
    //Health
    sf::RectangleShape line(sf::Vector2f(104, 15));
    line.setFillColor(sf::Color::Transparent);
    line.setOutlineThickness(2);
    line.setOutlineColor(sf::Color::White);
    line.setPosition(AssetManager::getXBackground() + 100, 50);

    sf::RectangleShape health(sf::Vector2f(Game::getGame()->getHero()->getHealthPoint()/10, 11));
    health.setFillColor(sf::Color::Red);
    health.setPosition(AssetManager::getXBackground() + 102, 52);

    //Munitions
    sf::Sprite currentAmmoSprite;
    currentAmmoSprite.setTexture(AssetManager::textures.at("MUNITIONS"));
    currentAmmoSprite.setPosition(line.getPosition().x + line.getSize().x + 50, line.getPosition().y - 5);
    currentAmmoSprite.setScale(0.05, 0.05);

    sf::Text nMunitions;
    nMunitions.setFont(*AssetManager::font);
    nMunitions.setString(std::to_string(Game::getGame()->getHero()->getAmmo()));
    nMunitions.setCharacterSize(20);
    nMunitions.setPosition(currentAmmoSprite.getPosition().x + 35, currentAmmoSprite.getPosition().y);

    //Coins
    sf::Sprite currentCoinsSprite;
    currentCoinsSprite.setTexture(AssetManager::textures.at("COINS"));
    currentCoinsSprite.setPosition(currentAmmoSprite.getPosition().x + 80, currentAmmoSprite.getPosition().y - 3);
    currentCoinsSprite.setScale(0.06, 0.06);

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

    //Show power up
    if (Game::getGame()->getHero()->isPowerUpState()) {
        sf::Text message;
        message.setFont(*AssetManager::font);
        message.setString(Game::getGame()->getHero()->getPowerUp().typeToString());
        message.setCharacterSize(25);
        message.setPosition(AssetManager::getXBackground() + targetWindow->getView().getSize().x / 2 -
                        message.getLocalBounds().width / 2, nCoins.getPosition().y + 3);
        targetWindow->draw(message);
    }


    popUp.setPosition(AssetManager::getXBackground() + targetWindow->getView().getSize().x -
                      popUp.getLocalBounds().width - 30, 20);

    if(achievementUnlocked){
        targetWindow->draw(popUp);
        if(achievementsClock->getElapsedTime().asSeconds() > 7)
            achievementUnlocked = false;
    }


}

void PlayState::animationHero(int direction, sf::Vector2f speed) {
    float speedClock = 0.08;

    if (Game::getGame()->getHero()->getClockAnimation()->getElapsedTime().asSeconds() > speedClock && direction == 0) {
        if (Game::getGame()->getHero()->getStrTexture().back() == 'd') {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_1_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Idle_1_Reversed");
        } else {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Idle_1"));
            Game::getGame()->getHero()->setStrTexture("Idle_1");
        }

    } else if (Game::getGame()->getHero()->getClockAnimation()->getElapsedTime().asSeconds() > speedClock &&
               direction > 0) {
        Game::getGame()->getHero()->getClockAnimation()->restart();
        if (Game::getGame()->getHero()->getStrTexture() == "Run_6" ||
            Game::getGame()->getHero()->getStrTexture() == "Idle_1"
            || Game::getGame()->getHero()->getStrTexture().back() == 'd') {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_1"));
            Game::getGame()->getHero()->setStrTexture("Run_1");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_1") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_2"));
            Game::getGame()->getHero()->setStrTexture("Run_2");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_2") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_3"));
            Game::getGame()->getHero()->setStrTexture("Run_3");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_3") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_4"));
            Game::getGame()->getHero()->setStrTexture("Run_4");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_4") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_5"));
            Game::getGame()->getHero()->setStrTexture("Run_5");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_5") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_6"));
            Game::getGame()->getHero()->setStrTexture("Run_6");
        }

    } else if (Game::getGame()->getHero()->getClockAnimation()->getElapsedTime().asSeconds() > speedClock &&
               direction < 0) {
        Game::getGame()->getHero()->getClockAnimation()->restart();
        if (Game::getGame()->getHero()->getStrTexture() == "Run_6_Reversed" ||
            Game::getGame()->getHero()->getStrTexture() == "Idle_1"
            || Game::getGame()->getHero()->getStrTexture() == "Idle_1_Reversed" ||
            Game::getGame()->getHero()->getStrTexture().back() != 'd') {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_1_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_1_Reversed");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_1_Reversed") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_2_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_2_Reversed");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_2_Reversed") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_3_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_3_Reversed");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_3_Reversed") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_4_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_4_Reversed");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_4_Reversed") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_5_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_5_Reversed");
        } else if (Game::getGame()->getHero()->getStrTexture() == "Run_5_Reversed") {
            Game::getGame()->getHero()->setTexture(AssetManager::textures.at("Run_6_Reversed"));
            Game::getGame()->getHero()->setStrTexture("Run_6_Reversed");
        }
    }

}

void PlayState::animationEnemies() {
    std::string color;

    for (const auto &enemy : Game::getGame()->getMap()->getEnemies()) {

        if (enemy->getBehaviorType() == "Wizard") {

            color = "Blue";

        } else if (enemy->getBehaviorType() == "Sentinel") {

            color = "Gray";

        } else {

            color = "Red";

        }

        animateEnemy(enemy, color);
    }
}

void PlayState::animateEnemy(const std::shared_ptr<Enemy> enemy, std::string color) {
    float speedClock = 0.12;

    if (enemy->getClockAnimation()->getElapsedTime().asSeconds() > speedClock && enemy->getDirection() == 0) {
        if (enemy->getStrTexture().back() == 'd') {
            enemy->setTexture(AssetManager::textures.at(color + "_Idle_1_Reversed"));
            enemy->setStrTexture(color + "_Idle_1_Reversed");
        } else {
            enemy->setTexture(AssetManager::textures.at(color + "_Idle_1"));
            enemy->setStrTexture(color + "_Idle_1");
        }
    }
    if (enemy->getClockAnimation()->getElapsedTime().asSeconds() > speedClock && enemy->getDirection() > 0) {
        enemy->getClockAnimation()->restart();
        if (enemy->getStrTexture() == color + "_Run_6" || enemy->getStrTexture() == color + "_Idle_1"
            || enemy->getStrTexture().back() == 'd') {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_1"));
            enemy->setStrTexture(color + "_Run_1");
        } else if (enemy->getStrTexture() == color + "_Run_1") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_2"));
            enemy->setStrTexture(color + "_Run_2");
        } else if (enemy->getStrTexture() == color + "_Run_2") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_3"));
            enemy->setStrTexture(color + "_Run_3");
        } else if (enemy->getStrTexture() == color + "_Run_3") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_4"));
            enemy->setStrTexture(color + "_Run_4");
        } else if (enemy->getStrTexture() == color + "_Run_4") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_5"));
            enemy->setStrTexture(color + "_Run_5");
        } else if (enemy->getStrTexture() == color + "_Run_5") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_6"));
            enemy->setStrTexture(color + "_Run_6");
        } else {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_1"));
            enemy->setStrTexture(color + "_Run_1");
        }

    } else if (enemy->getClockAnimation()->getElapsedTime().asSeconds() > speedClock && enemy->getDirection() < 0) {
        enemy->getClockAnimation()->restart();
        if (enemy->getStrTexture() == color + "_Run_6_Reversed" || enemy->getStrTexture() == color + "_Idle_1"
            || enemy->getStrTexture() == color + "_Idle_1_Reversed" || enemy->getStrTexture().back() != 'd') {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_1_Reversed"));
            enemy->setStrTexture(color + "_Run_1_Reversed");
        } else if (enemy->getStrTexture() == color + "_Run_1_Reversed") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_2_Reversed"));
            enemy->setStrTexture(color + "_Run_2_Reversed");
        } else if (enemy->getStrTexture() == color + "_Run_2_Reversed") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_3_Reversed"));
            enemy->setStrTexture(color + "_Run_3_Reversed");
        } else if (enemy->getStrTexture() == color + "_Run_3_Reversed") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_4_Reversed"));
            enemy->setStrTexture(color + "_Run_4_Reversed");
        } else if (enemy->getStrTexture() == color + "_Run_4_Reversed") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_5_Reversed"));
            enemy->setStrTexture(color + "_Run_5_Reversed");
        } else if (enemy->getStrTexture() == color + "_Run_5_Reversed") {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_6_Reversed"));
            enemy->setStrTexture(color + "_Run_6_Reversed");
        } else {
            enemy->setTexture(AssetManager::textures.at(color + "_Run_1_Reversed"));
            enemy->setStrTexture(color + "_Run_1_Reversed");
        }
    }

}

void PlayState::detectCollision(const std::shared_ptr<GameCharacter> &entity, const std::shared_ptr<sf::Sprite> &block,
                                sf::Vector2f &moving) {


    sf::Vector2f entityPos = entity->getPosition();
    sf::Vector2u entitySize = entity->getTexture()->getSize();
    sf::Vector2f entityScale = entity->getScale();

    entityPos.x += entitySize.x * entityScale.x / 2.0f;
    entityPos.y += entitySize.y * entityScale.y / 2.0f;

    float deltaX = entityPos.x + moving.x -
                   (block->getPosition().x + block->getTexture()->getSize().x * block->getScale().x / 2.0f);
    float intersectionX = std::fabs(deltaX) - ((entitySize.x * entityScale.x / 2) +
                                               (block->getTexture()->getSize().x * block->getScale().x / 2.0f));
    float deltaY = entityPos.y + moving.y -
                   (block->getPosition().y + block->getTexture()->getSize().y * block->getScale().y / 2.0f);
    float intersectionY = std::fabs(deltaY) - ((entitySize.y * entityScale.y / 2) +
                                               (block->getTexture()->getSize().y * block->getScale().y / 2.0f));

    bool rightCollisionBool = false;
    bool leftCollisionBool = false;
    bool bottomtCollisionBool = false;
    bool topCollisionBool = false;

    int rightCollision = 0;
    int leftCollision = 0;
    int bottomtCollision = 0;
    int topCollision = 0;


    if (intersectionY < 0.0f && intersectionX < 0.0f) { //se entra qui collide con un blocco

        if (intersectionX > intersectionY) {
            if (deltaX > 0.0f) {
                leftCollision++;
                leftCollisionBool = true;
            } else {
                rightCollision++;
                rightCollisionBool = true;
            }
        } else {
            if (deltaY < 0.0f) {
                bottomtCollision++;
                bottomtCollisionBool = true;
            } else {
                topCollision++;
                topCollisionBool = true;
            }
        }

        if (leftCollision == 1 && leftCollisionBool) {
            moving.x -= intersectionX;
            entity->setSpeed(sf::Vector2f(0, entity->getSpeed().y));
        }

        if (rightCollision == 1 && rightCollisionBool) {
            moving.x += intersectionX;
            entity->setSpeed(sf::Vector2f(0, entity->getSpeed().y));
        }

        if (topCollision == 1 && topCollisionBool) {
            moving.y -= intersectionY;
            entity->setSpeed(sf::Vector2f(entity->getSpeed().x, 0));
        }

        if (bottomtCollision == 1 && bottomtCollisionBool) {
            moving.y += intersectionY;
            entity->setSpeed(sf::Vector2f(entity->getSpeed().x, 0));
        }

    }

}


sf::Vector2f PlayState::isLegalMovement(const std::shared_ptr<GameCharacter> &entity, sf::Vector2f move) {
    sf::Vector2f moving = move;

    for (const auto &block : Game::getGame()->getMap()->getMatrix()) {
        detectCollision(entity, block, moving);
    }

    return moving;
}

bool PlayState::checkCollision(const std::shared_ptr<sf::Sprite> &entity1, const std::shared_ptr<sf::Sprite> &entity2) {
    bool collision = false;

    sf::Vector2f entityPos = entity1->getPosition();
    sf::Vector2u entitySize = entity1->getTexture()->getSize();
    sf::Vector2f entityScale = entity1->getScale();

    entityPos.x += entitySize.x * entityScale.x / 2.0f;
    entityPos.y += entitySize.y * entityScale.y / 2.0f;

    float deltaX = entityPos.x -
                   (entity2->getPosition().x + entity2->getTexture()->getSize().x * entity2->getScale().x / 2.0f);
    float deltaY = entityPos.y -
                   (entity2->getPosition().y + entity2->getTexture()->getSize().y * entity2->getScale().y / 2.0f);
    float intersectionX = std::fabs(deltaX) - ((entitySize.x * entityScale.x / 2) +
                                               (entity2->getTexture()->getSize().x * entity2->getScale().x / 2.0f));
    float intersectionY = std::fabs(deltaY) - ((entitySize.y * entityScale.y / 2) +
                                               (entity2->getTexture()->getSize().y * entity2->getScale().y / 2.0f));

    if (intersectionY < 0.0f && intersectionX < 0.0f) {
        collision = true;
    }

    return collision;
}


void PlayState::checkCollectables() {
    int i = 0;
    for (const auto &collectable : Game::getGame()->getMap()->getCollectables()) {
        if (checkCollision(collectable, Game::getGame()->getHero()))
            collectable->notifyObservers(i);
        i++;
    }
}

void PlayState::checkBullets() {
    int i = 0, hp = 0;
    int cont = 0;
    bool deleted = false, killedHero = false;
    for (const auto &bullet : Game::getGame()->getMap()->getBullets()) {
        bullet->move(Game::getGame()->getClock()->getElapsedTime().asSeconds());
        deleted = false;
        if (!spriteInView(*bullet)) {
            deleted = true;
            Game::getGame()->getMap()->removeBullet(i);
            //std::cout<<"Removed or view"<<std::endl;
        } else if (checkCollision(bullet, Game::getGame()->getHero()) && !bullet->isFriendly()) {
            deleted = true;
            hp = Game::getGame()->getHero()->receiveDamage(bullet->getDamage());
            Game::getGame()->getMap()->removeBullet(i);
            if (hp < 1) {
                killedHero = true;
            }
        } else {
            if (!deleted) {
                cont = 0;
                for (const auto &enemy : Game::getGame()->getMap()->getEnemies()) {
                    if (checkCollision(bullet, enemy) && bullet->isFriendly() && !deleted) {
                        deleted = true;
                        hp = enemy->receiveDamage(bullet->getDamage()*Game::getGame()->getHero()->getDamageBoost());
                        Game::getGame()->getMap()->removeBullet(i);

                        if (hp < 1) {
                            Game::getGame()->getMap()->removeEnemy(cont);

                            bool unlocked = false;
                            EVENT e = EVENT::KILL;
                            notifyObservers(e, unlocked);
                            if(unlocked)
                                showAchievement(e);
                        }
                    }
                    cont++;

                }
            }
            if (!deleted) {
                for (const auto &block : Game::getGame()->getMap()->getMatrix()) {
                    if (checkCollision(bullet, block) && !deleted) {
                        deleted = true;
                        Game::getGame()->getMap()->removeBullet(i);
                    }
                }
            }

        }
        i++;
    }



    if (killedHero){

        bool unlocked = false;
        EVENT e = EVENT::DEATH;
        notifyObservers(e, unlocked);
        if(unlocked)
            showAchievement(e);

        Game::getGame()->killHero();
    }


}

bool PlayState::spriteInView(const sf::Sprite &sprite) {
    sf::Vector2f viewSize(targetWindow->getView().getSize());
    sf::Vector2f viewCenter(targetWindow->getView().getCenter());

    sf::Vector2i spritePosition = sf::Vector2i(sprite.getPosition());

    return !(std::fabs(spritePosition.x - viewCenter.x) > viewSize.x / 2 ||
             std::fabs(spritePosition.y - viewCenter.y) > viewSize.y / 2);
}

int PlayState::getAction() const {
    return action;
}

void PlayState::setAction(int action) {
    PlayState::action = action;
}

void PlayState::behaviorChanger() {
    int i = 1;
    for (const auto &enemy : Game::getGame()->getMap()->getEnemies()) {
        enemyBehaviorChanger(enemy);
        i++;
    }
}

void PlayState::enemyBehaviorChanger(const std::shared_ptr<Enemy> &enemy) {
    sf::Vector2f moveEnemy = sf::Vector2f(0, 0);
    sf::Vector2f movmentCollision;
    float eps=10.0f;
    bool found;
    std::shared_ptr<Bullet> b = nullptr;

    if (enemy->getBehavior() == "patrol") {
        if (enemy->getClockPatrol()->getElapsedTime().asSeconds() > 3.0f) {

            enemy->setDirection(enemy->getDirection() * (-1.0f));
            enemy->getClockPatrol()->restart();

        }

        found = enemy->patrol(Game::getGame()->getClock()->getElapsedTime().asSeconds(),
                sf::Vector2f(Game::getGame()->getHero()->getPosition()), &moveEnemy);
        movmentCollision=moveEnemy;
        moveEnemy = isLegalMovement(enemy, sf::Vector2f(moveEnemy));


        if(std::abs(movmentCollision.x-moveEnemy.x)>eps){
            enemy->setDirection(enemy->getDirection()*(-1.0f));
            enemy->sf::Sprite::move(sf::Vector2f(moveEnemy.x*-1.0f,moveEnemy.y));
            enemy->getClockPatrol()->restart();
        }
        else
            enemy->sf::Sprite::move(sf::Vector2f(moveEnemy));


        if (found) {
            enemy->setBehavior("fight");
        }


    } else if (enemy->getBehavior() == "fight") {

        b = enemy->fight(sf::Vector2f(Game::getGame()->getHero()->sf::Sprite::getPosition()), moveEnemy,
                         Game::getGame()->getClock()->getElapsedTime().asSeconds());


        moveEnemy = isLegalMovement(enemy, sf::Vector2f(moveEnemy));

        if (enemy->checkJump() &&
            std::fabs(enemy->sf::Sprite::getPosition().x - Game::getGame()->getHero()->sf::Sprite::getPosition().x) >
            50) {
            enemy->jump();
        }

        enemy->sf::Sprite::move(sf::Vector2f(moveEnemy));


        if (b != nullptr) {
            if (enemy->fireClock(enemy->getWeapon()->getFireRate())) {
                Game::getGame()->getMap()->addBullet(b);
            }
        }
    }
}

void PlayState::removeObserver(Observer* observer) {
    observers.remove(observer);
}

void PlayState::registerObserver(Observer* observer) {
    observers.push_back(observer);
}

void PlayState::notifyObservers(EVENT e, bool &unlocked) const {
    for (const auto &observer : observers)
        observer->update(e,unlocked);
}

PlayState::~PlayState() {
    removeObserver(&(*Game::getGame()->getAchievements()));
}

void PlayState::showAchievement(EVENT e) {

    achievementUnlocked = true;

    achievementsClock->restart();

    std::string message;

    switch (e) {
        case EVENT::KILL:
            message = "You killed " N_KILLS_STR " enemies!";
            break;
        case EVENT::JUMP:
            message = "You jumped " N_JUMPS_STR " time!";
            break;
        case EVENT::BULLET_SHOT:
            message = "You shot " N_BULLETS_STR " bullets!";
            break;
        case EVENT::DEATH:
            message = "You dead " N_DEATHS_STR " time!";
            break;
        case EVENT::FALL:
            message = "You fell " N_FALLS_STR " time!";
            break;
        default:
            break;
    }

    popUp.setFont(*AssetManager::font);
    popUp.setString("Achevement unlocked: " + message);
    popUp.setCharacterSize(30);


}
