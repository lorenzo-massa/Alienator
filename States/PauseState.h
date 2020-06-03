//
// Created by Lorenzo Massa on 02/06/2020.
//

#ifndef ALIENATOR_PAUSESTATE_H
#define ALIENATOR_PAUSESTATE_H

#include "GameState.h"
#include "../MainMenu.h"

class PauseState : public GameState{
public:
    PauseState(std::shared_ptr<sf::RenderWindow> targetWindow);
    void handleInput() override;
    void frameCalculator() override;
    void generateFrame() override;
private:
    MainMenu mainMenu;
};


#endif //ALIENATOR_PAUSESTATE_H