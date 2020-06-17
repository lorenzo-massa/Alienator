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
    sf::Vector2f isLegalMovement(sf::Sprite entity,sf::Vector2f move);
private:

    int action;
    void generateMap();

    void generateGUI(float& xT);

    void animationHero(int direction, sf::Vector2f speed);
};


#endif //ALIENATOR_PLAYSTATE_H
