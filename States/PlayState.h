//
// Created by th3lo on 31/05/2020.
//

#ifndef ALIENATOR_PLAYSTATE_H
#define ALIENATOR_PLAYSTATE_H


#include "GameState.h"

class PlayState : public GameState{
public:
    PlayState(std::shared_ptr<sf::RenderWindow> targetWindow);
    void handleInput() override;
    void frameCalculator() override;
    void generateFrame() override;
    bool isLegalMovement();
private:

    int action;
    void generateMap();

};


#endif //ALIENATOR_PLAYSTATE_H
