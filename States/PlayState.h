//
// Created by th3lo on 31/05/2020.
//

#ifndef ALIENATOR_PLAYSTATE_H
#define ALIENATOR_PLAYSTATE_H


#include "GameState.h"
#include "../GameCharacter/GameCharacter.h"

class PlayState : public GameState{
public:
    PlayState(std::shared_ptr<sf::RenderWindow> targetWindow);
    void handleInput() override;
    void frameCalculator() override;
    void generateFrame() override;
    bool isLegalMovement(GameCharacter& entity,sf::Vector2f move);
private:

    int action;
    void generateMap();

    void generateGUI(float& xT);
};


#endif //ALIENATOR_PLAYSTATE_H
