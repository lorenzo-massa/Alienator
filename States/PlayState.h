//
// Created by Lorenzo Massa on 31/05/2020.
//

#ifndef ALIENATOR_PLAYSTATE_H
#define ALIENATOR_PLAYSTATE_H


#include "GameState.h"
#include "../GameCharacter/Hero.h"

class PlayState : public GameState{
public:
    PlayState(std::shared_ptr<sf::RenderWindow> targetWindow, int level);
    void handleInput() override;
    void generateFrame() override;
    sf::Vector2f isLegalMovement(std::shared_ptr<GameCharacter> entity, sf::Vector2f move);

    int getAction() const;

    void setAction(int action);

    const std::shared_ptr<sf::Clock> &getClock() const;

    void setClock(const std::shared_ptr<sf::Clock> &clock);

    const std::shared_ptr<sf::Clock> &getClockEnemies() const;

    void setClockEnemies(const std::shared_ptr<sf::Clock> &clockEnemies);

private:

    int action;
    std::shared_ptr<sf::Clock> clock;
    std::shared_ptr<sf::Clock> clockEnemies;
    std::shared_ptr<sf::Clock> directionClock;
    std::shared_ptr<sf::Clock> combactClock;

    void generateMap();

    void generateGUI(float& xT);

    void animationHero(int direction, sf::Vector2f speed);

    void animationEnemies();

    void checkCollectables();

    bool checkCollision(std::shared_ptr<sf::Sprite> entity1, std::shared_ptr<sf::Sprite> entity2);

    bool spriteInView(sf::Sprite sprite);

    bool patrolClock();

    bool fireClock(float fireRate);

    void checkBullets();

    void checkFinished();
};


#endif //ALIENATOR_PLAYSTATE_H
