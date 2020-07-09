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

    const std::shared_ptr<sf::Clock> &getClock() const;

    void setClock(const std::shared_ptr<sf::Clock> &clock);

    const std::shared_ptr<sf::Clock> &getClockEnemies() const;

    void setClockEnemies(const std::shared_ptr<sf::Clock> &clockEnemies);

    bool checkCollision(const std::shared_ptr<sf::Sprite>& entity1, const std::shared_ptr<sf::Sprite>& entity2);

    void checkFinished();



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

    void behaviorChanger();
};


#endif //ALIENATOR_PLAYSTATE_H
