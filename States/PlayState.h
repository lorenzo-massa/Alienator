//
// Created by th3lo on 31/05/2020.
//

#ifndef ALIENATOR_PLAYSTATE_H
#define ALIENATOR_PLAYSTATE_H


#include "GameState.h"
#include "../GameCharacter/Hero.h"

class PlayState : public GameState{
public:
    PlayState(std::shared_ptr<sf::RenderWindow> targetWindow);
    void handleInput() override;
    void generateFrame() override;
    sf::Vector2f isLegalMovement(std::shared_ptr<GameCharacter> entity, sf::Vector2f move);
private:

    int action;
    std::shared_ptr<sf::Clock> clock;
    std::shared_ptr<sf::Clock> clockEnemies;

    void generateMap();

    void generateGUI(float& xT);

    void animationHero(int direction, sf::Vector2f speed);

    void animationEnemies();

    void checkCollectables();

    bool checkCollision(std::shared_ptr<sf::Sprite> entity1, std::shared_ptr<sf::Sprite> entity2);
};


#endif //ALIENATOR_PLAYSTATE_H
