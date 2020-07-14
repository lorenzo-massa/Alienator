//
// Created by Lorenzo Massa on 02/06/2020.
//

#ifndef ALIENATOR_PAUSESTATE_H
#define ALIENATOR_PAUSESTATE_H

#include "GameState.h"
#include "../Menu/MainMenu.h"

class PauseState : public GameState {
public:
    explicit PauseState(std::shared_ptr<sf::RenderWindow> targetWindow);

    ~PauseState() override;

    void handleInput() override;

    void generateFrame() override;

private:
    MainMenu mainMenu;
};


#endif //ALIENATOR_PAUSESTATE_H
