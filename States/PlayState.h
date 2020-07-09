//
// Created by Lorenzo Massa on 31/05/2020.
//

#ifndef ALIENATOR_PLAYSTATE_H
#define ALIENATOR_PLAYSTATE_H


#include "GameState.h"
#include "../GameCharacter/Hero.h"
#include "../Engine/Game.h"
#include "PauseState.h"

class PlayState : public GameState{
public:
    PlayState(const std::shared_ptr<sf::RenderWindow>& targetWindow, int level);
    void handleInput() override;
    void generateFrame() override;
    sf::Vector2f isLegalMovement(const std::shared_ptr<GameCharacter>& entity, sf::Vector2f move);

    int getAction() const;

    void setAction(int action);

    bool checkCollision(const std::shared_ptr<sf::Sprite>& entity1, const std::shared_ptr<sf::Sprite>& entity2);

    void checkFinished();

    void behaviorChanger();


    void enemyBehaviorChanger(std::shared_ptr<Enemy> enemy);

    void detectCollision(const std::shared_ptr<GameCharacter> &entity, const std::shared_ptr<sf::Sprite> &block,
                         sf::Vector2f &moving);

private:

    int action;

    std::shared_ptr<sf::Clock> directionClock;
    std::shared_ptr<sf::Clock> combactClock;

    void generateMap();

    void generateGUI(float& xT);

    void animationHero(int direction, sf::Vector2f speed);

    void animationEnemies();

    void checkCollectables();


    bool spriteInView(sf::Sprite sprite);

    bool patrolClock();

    bool fireClock(float fireRate);

    void checkBullets();

    void animateEnemy(std::shared_ptr<Enemy> enemy, std::string color);

    sf::Vector2f
    detectCollision(const std::shared_ptr<GameCharacter> &entity, const std::shared_ptr<Block> &block,
                    sf::Vector2f moving);

};


#endif //ALIENATOR_PLAYSTATE_H
